#include <cstdio>
long long T,n,m,k;

int main()
{
	scanf("%lld",&T);
	while (T--)
	{
		scanf("%lld%lld%lld",&n,&m,&k);
		printf("%lld\n",(n/k)*(m/k));
	}
	return 0;
}
