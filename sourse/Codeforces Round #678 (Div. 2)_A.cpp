#include <cstdio>
#include <algorithm>
int T,n,m,a;

int main()
{
	scanf("%d",&T);
	while (T--)
	{
		scanf("%d%d",&n,&m);
		for (int i=1; i<=n; i++)
		{
			scanf("%d",&a);
			m-=a;
		}
		printf(m?"NO\n":"YES\n");
	}
	return 0;
}
