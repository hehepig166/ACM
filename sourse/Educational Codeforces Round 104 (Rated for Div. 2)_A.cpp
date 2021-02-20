#include <bits/stdc++.h>
using namespace std;
int n,a[200];

void solve()
{
	scanf("%d",&n);
	for (int i=1; i<=n; i++)
		scanf("%d",&a[i]);
	sort(a+1,a+n+1);
	int ans=n;
	for (int i=1; i<=n; i++)
	{
		if (a[i]==a[1])
			ans--;
		else
			break;
	}
	printf("%d\n",ans);
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

