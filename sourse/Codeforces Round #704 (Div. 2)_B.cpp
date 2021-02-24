#include <bits/stdc++.h>
using namespace std;

int n,p[100005],M[100005],maxid;

void solve()
{
	scanf("%d",&n);
	for (int i=1; i<=n; i++)
		scanf("%d",&p[i]);
	
	maxid=1;
	for (int i=1; i<=n; i++)
		M[i]= p[i]>=p[maxid] ? (maxid=i) : maxid;
	
	for (int i=n; i; i--)
	{
		for (int j=M[i]; j<=i; j++)
			printf("%d ",p[j]);
		i=M[i];
	}

	puts("");
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
