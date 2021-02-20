#include <cstdio>
#include <algorithm>
#define I c[i]
using namespace std;
long long ans,n,t,f[10002],p[10002],d[10002],c[10002];

bool cmp(long long x, long long y)
{
	return p[x]>p[y];
}

long long Fa(long long &x)
{
	return f[x]==x ? x : f[x]=Fa(f[x]);
}

int main()
{
	while (scanf("%lld",&n)==1)
	{
		ans=0;
		for (long long i=0; i<=10000; i++)
			f[i]=i;
		for (long long i=1; i<=n; i++)
		{
			scanf("%lld%lld",&p[i],&d[i]);
			c[i]=i;
		}
		sort(c+1,c+n+1,cmp);
		
		for (long long i=1; i<=n; i++)
		{
			t=Fa(d[I]);
			if (t>0)
			{
				ans+=p[I];
				f[t]=t-1;
			}
		}
		
		printf("%lld\n",ans);
		
	}
	return 0;
}
