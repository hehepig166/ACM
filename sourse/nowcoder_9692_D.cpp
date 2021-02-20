#include <cstdio>
long long T,n,p,ans;

int main()
{
	scanf("%lld",&T);
	while (T--)
	{
		scanf("%lld%lld",&n,&p);
		ans=0;
		for (long long tmp=p; tmp<=n; tmp*=p)
			ans+=n/tmp;
		printf("%lld\n",ans);
	}
	
	return 0;
}
