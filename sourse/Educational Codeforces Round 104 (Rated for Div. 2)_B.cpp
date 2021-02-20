#include <bits/stdc++.h>
using namespace std;

void solve()
{
	long long n,k,ans,m;
	scanf("%lld%lld",&n,&k);
	if (n%2==0)
	{
		ans=(k-1)%n+1;
		printf("%lld\n",ans);
		return;
	}
	else
	{
		m=n/2;
		ans=(((k-1)/m+k)-1)%n+1;
		printf("%lld\n",ans);
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

