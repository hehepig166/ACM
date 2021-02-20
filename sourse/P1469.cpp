#include <cstdio>
typedef int LL;
LL n,s;

LL rd()
{
	static char ch;
	static LL ret;
	for (ch=getchar(); ch<'0' || ch>'9'; ch=getchar());
	for (ret=0; ch>='0' && ch<='9'; ch=getchar())
		ret=(ret<<1)+(ret<<3)+ch-'0';
	return ret;
}

int main()
{
	n=rd();
	while (n--)
		s^=rd();
	printf("%lld\n",s);
	return 0;
}
