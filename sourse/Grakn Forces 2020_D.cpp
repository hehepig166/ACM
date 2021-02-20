#include <bits/stdc++.h>
#define N 2000
using namespace std;
int ans,tot,n,m,a[N+5],b[N+5],c[N*N+5],d[N+5],Max[N*N+5],mR[N*N+5],mD[N*N+5];
bool cmp(long long x,long long y)
{
	return mR[x]==mR[y] ? mD[x]<mD[y] : mR[x]>mR[y];
}

void rd(int &ret)
{
	ret=0;
	char ch=getchar();
	for (; ch<'0' || ch>'9'; ch=getchar());
	for (; ch>='0' && ch<='9'; ch=getchar()) ret=(ret<<3)+(ret<<1)+ch-'0';
}

int main()
{
	//freopen("1.txt","r",stdin);
	rd(n); rd(m);
	ans=2147483647;
	tot=0;
	for (int i=1; i<=n; i++) {rd(a[i]); rd(b[i]);}
	for (int i=1; i<=m; i++) {rd(c[i]); rd(d[i]);}
	for (int i=1; i<=n; i++)
		for (int j=1; j<=m; j++)
		{
			tot++;
			mR[tot]=max(0,d[j]-b[i]+1);
			mD[tot]=max(0,c[j]-a[i]+1);
		}
	for (int i=1; i<=tot; i++) c[i]=i;
	sort(c+1,c+tot+1,cmp);
	mD[0]=mR[tot+1]=Max[0]=0;
	for (int i=1; i<=tot; i++) Max[i]=max(Max[i-1],mD[c[i]]);
	
	for (int i=1; i<=tot; i++)	//1~i-1 :D  i~tot  :R
	{
		ans=min(Max[i-1]+mR[c[i]],ans);
	}
	ans=min(ans,Max[tot]);
	printf("%d",ans);
}
