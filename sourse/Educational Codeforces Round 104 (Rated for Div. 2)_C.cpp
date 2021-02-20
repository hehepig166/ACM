#include <bits/stdc++.h>
using namespace std;

void solve()
{
	int n,m;
	scanf("%d",&n);
	if (n%2==1)
	{
		for (int i=1; i<n; i++)
			for (int j=i+1,k=1; j<=n; j++,k^=1)
				printf("%d ",(k&1) ?  1 : -1);
		puts("");
		return;
	}
	else
	{
		m=n/2;
		for (int i=1; i<n; i++)
		{
			for (int j=i+1,k=1; j<=n; j++)
			{
				if (j==i+m)
				{
					printf("0 ");
					continue;
				}
				else
				{
					printf("%d ",(k&1) ? 1 : -1);
					k^=1;
				}
			}
		}
		puts("");
		return;
	}
}

int main()
{
	int t;
	scanf("%d",&t);
	while (t--)
	{
		solve();
	}
	return 0;
}

