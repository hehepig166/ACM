#include <bits/stdc++.h>
using namespace std;
#define MaxN 200005
char S[MaxN],T[MaxN];
int n,m;
int tmp[30],Lid[MaxN][30],Rid[MaxN][30],L[MaxN],R[MaxN];

void solve()
{
	scanf("%d%d",&n,&m);
	scanf("%s%s",S+1,T+1);
	for (int i=1; i<=n; i++) S[i]-='a';
	for (int i=1; i<=m; i++) T[i]-='a';
	
	for (int i=0; i<26; i++)
		tmp[i]=0;
	for (int i=1; i<=n; i++)
	{
		for (int j=0; j<26; j++) Lid[i][j]=tmp[j];
		tmp[S[i]]=i;
	}
	for (int j=0; j<26; j++) Lid[n+1][j]=tmp[j];
	
	for (int i=0; i<26; i++)
		tmp[i]=n+1;
	for (int i=n; i>=1; i--)
	{
		for (int j=0; j<26; j++) Rid[i][j]=tmp[j];
		tmp[S[i]]=i;
	}
	for (int j=0; j<26; j++) Rid[0][j]=tmp[j];
	
	L[0]=0;
	for (int i=1; i<=m; i++)
		L[i]=Rid[L[i-1]][T[i]];
	R[m+1]=n+1;
	for (int i=m; i; i--)
		R[i]=Lid[R[i+1]][T[i]];
	
	int ans=0;
	
	for (int i=1; i<m; i++)
		if (L[i] < R[i+1])
			ans=max(ans,R[i+1]-L[i]);
	
	printf("%d\n",ans);
	
}

int main()
{
	solve();
}

