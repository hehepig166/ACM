#include <cstdio>
long long T,s,n,k,a[300000],b[300000];

int main()
{
	scanf("%lld",&T);
	while (T--)
	{
		s=0;
		scanf("%lld%lld",&n,&k);
		for (int i=1,j=n*k; i<=j; i++)
			scanf("%lld",&a[i]);
		for (int i=1,r=n*k,l=1; i<=k; i++)
		{
			int j=n,J=(n-1)/2+1;
			for (; j>=J; j--)
				b[j]=a[r--];
			s+=b[J];
		}
		printf("%lld\n",s);
	}
	return 0;
}
