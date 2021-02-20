#include <cstdio>
int T,n;

int main()
{
	scanf("%d",&T);
	while (T--)
	{
		scanf("%d",&n);
		for (int i=0; i<n; i++)
		{
			for (int j=0; j<n; j++)
				printf((j==i || j==(i+1)%n) ? "1 " : "0 ");
			printf("\n");
		}
	}
	return 0;
}
