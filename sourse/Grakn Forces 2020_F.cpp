#include <cstdio>
long long n,N;

int main()
{
	scanf("%lld",&n);
	if (n==1 || n==2)
	{
		printf("0\n");
		return 0;
	}
	if (n==3)
	{
		printf("1\n1 2");
		return 0;
	}
	
	a[1][2]=0,a[1][1]=1;
	for (int i=2; i<=30; i++)
		a[i][2]=a[i-1][1]*2,a[i][1]=a[i][2]+(1ll<<(i-1));
	
	for (N=0,tmp=1; tmp<<=1; N++)
	{
		if (n==tmp)
		{
			printf("%lld",a[N][2]);
			return 0;
		}
		if (tmp>n-2)
		{
			N-=1;
			tmp>>=1;			
		}
	}
	
	return 0;
}
