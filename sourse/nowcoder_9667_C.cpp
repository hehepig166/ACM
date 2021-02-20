#include <cstdio>
long long n,ans=0;

int main()
{
	scanf("%lld",&n);
	
	ans=2*(n/4);
	n-=ans*2;
	
	switch(n)
	{
		case 3:
			ans+=1;
			break;
		default:
			ans+=n;
	}
	
	printf("%lld",ans);
	return 0;
}
