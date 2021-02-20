#include <cstdio>

int main()
{
	long long i,j,n,a3,a5,A;
	scanf("%lld",&n);
	
	for (i=1,a3=3; a3<=n; i++,a3*=3ll)
	{
		for (j=1,a5=5; a5+a3<=n; j++,a5*=5ll)
		{
			A=a3+a5;
			if (A==n)
			{
				printf("%lld %lld",i,j);
				return 0;
			}
		}
	}
	printf("-1");
	return 0;
}
/*
3^20	3486784401
5^24	59604644775390625
59604648262175027
*/
