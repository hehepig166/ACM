#include <cstdio>
#include <algorithm>
#define I b[i]
using namespace std;
int n,m,p[2000005],a[2000005],b[2000005];
long long ans=0;
bool cmp(int x,int y){return p[x]<p[y];}

int main()
{
	scanf("%d%d",&n,&m);
	for (int i=b[1]=1; i<=m; b[i]=++i)
		scanf("%d%d",&p[i],&a[i]);
	sort(b+1,b+m+1,cmp);
	for (int i=1; i<=m; i++)
	{
		if (n<=a[I])
		{
			ans+=n*p[I];
			printf("%lld",ans);
			return 0;
		}
		ans+=a[I]*p[I];
		n-=a[I];
	}
	printf("0");
	return 0;
}
