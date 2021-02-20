#include <cstdio>
int T,n;

int main()
{
	scanf("%d",&T);
	while (T--)
	{
		scanf("%d",&n);
		if (n==1)
		{
			printf("0\n");
			continue;
		}
		if (n==2)
		{
			printf("1\n");
			continue;
		}
		if (n==3)
		{
			printf("2\n");
			continue;
		}
		if (n%2==0)
		{
			printf("2\n");
			continue;
		}
		printf("3\n");
		continue;
	}
	
	return 0;
}
