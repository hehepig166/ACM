#include <bits/stdc++.h>
using namespace std;

int n;
int a[200005],c[200005];
vector<pair<int,int>> f[5000005];

bool cmp(int x, int y){return a[x]<a[y];}

#define I c[i]
#define J c[j]

void solve()
{
	scanf("%d",&n);
	for (int i=1; i<=n; i++)
	{
		scanf("%d",&a[i]);
		c[i]=i;
	}
		
	sort(c+1,c+n+1,cmp);
	
	for (int i=1,mi=min(n,5000); i<mi; i++)
	{
		for (int j=i+1; j<=mi; j++)
		{
			int sum=a[I]+a[J];
			if (!f[sum].empty())
			{
				for (auto A: f[sum])
				{
					if (A.first!=I && A.first!=J && A.second!=I && A.second!=J)
					{
						puts("YES");
						printf("%d %d %d %d\n",A.first, A.second, I,J);
						return;
					}
				}
			}
			f[sum].emplace_back(make_pair(I,J));
		}
	}
	
	puts("NO");
}

int main()
{
	solve();
	return 0;
}
