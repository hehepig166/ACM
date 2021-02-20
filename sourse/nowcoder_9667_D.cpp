#include <cstdio>
#define N 200005
long long p[N],f[N]={0};
long long cnt=0,ans,n;

int main()
{
	scanf("%lld",&n);
	
	if (n==1 || n==2 || n==3)
	{
		printf("-1");
		return 0;
	}
	
	
	for (long long i=2; i<=n; i++)
	{
		if (!f[i])
			p[++cnt]=i;
		
		for (long long j=1; j<=cnt && p[j]*i<=n; j++)
		{
			f[p[j]*i]=1;
			
			if (i%p[j]==0)
				break;
		}
	}
	
	ans=2;
	for (long long i=1; i<=cnt; i++)
	{
		if (p[i]<=n)
			ans++;
		else
			break;
	}
	
	printf("%lld",ans);
	return 0;
}
