#include <cstdio>

int main()
{
	scanf("%d",&T);
	while (T--)
	{
		scanf("%d%d%d%d",&x,&n,&s,&l,&r);
		if (l>r) r+=n;
	}
}
