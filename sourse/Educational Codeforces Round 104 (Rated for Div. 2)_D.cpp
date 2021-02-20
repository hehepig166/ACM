#include <bits/stdc++.h>
using namespace std;

void solve()
{
	static long long n,ans;
	static long long Maxa;
	static double tmp;
	scanf("%lld",&n);
	tmp=sqrt(2*n-1);
	Maxa=(long long) tmp;
	ans=(Maxa-1)/2;
	printf("%lld\n",ans);
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

