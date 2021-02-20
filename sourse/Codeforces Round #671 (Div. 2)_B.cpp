#include <cstdio>
long long a[50],n,t,ans;


int main()
{
	
	a[1]=1;
	for (long long i=2,k=3; i<=31; i++,k=k*2+1)
	{
		a[i]=(k+1)*k/2;
		//printf("[%lld]\t%lld\n",i,a[i]);
	}
	scanf("%lld",&t);
	while (t--)
	{
		scanf("%lld",&n);
		for (ans=1; n>=0 && ans<=31; )
		{
			n-=a[ans];
			if (n==0) break;
			if (n<0)
			{
				ans--;
				break;
			}
			ans++;
		}
		printf("%lld\n",ans);
	}
	return 0;
	
}
