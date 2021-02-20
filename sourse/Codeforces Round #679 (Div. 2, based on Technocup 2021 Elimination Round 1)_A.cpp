#include <cstdio>
int T,n,a,b;

int main()
{
	scanf("%d",&T);
	while (T--)
	{
		scanf("%d",&n);
		for (int i=1,j=n/2; i<=j; i++)
		{
			scanf("%d%d",&a,&b);
			printf("%d %d ",-b,-a);
		}
		printf("\n");
	}
	return 0;
}
