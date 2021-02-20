#include <bits/stdc++.h>
using namespace std;
long long n,m,a[3000][3000],b[3000][3000];

int main()
{
	
	scanf("%lld%lld",&n,&m);
	for (int i=1; i<=n; i++)
		for (int j=1; j<=m; j++)
		{
			scanf("%lld",&a[i][j]);
			if (((i^j)&1))
				b[i][j]=720720;
			else
				b[i][j]=720720-a[i][j]*a[i][j]*a[i][j]*a[i][j];
		}
	
	for (int i=1; i<=n; i++)
	{
		for (int j=1; j<m; j++)
			printf("%lld ",b[i][j]);
		printf("%lld\n",b[i][m]);
	}
}
