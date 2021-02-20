#include <cstdio>

int main()
{
	long long a;
	scanf("%lld",&a);
	printf("%lld",a/65536+a%65536*65536);
	return 0;
}
