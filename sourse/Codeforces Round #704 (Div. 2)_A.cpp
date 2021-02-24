#include <bits/stdc++.h>
using namespace std;

void solve()
{
	long long p,a,b,c,t1,t2,t3,ans;
	scanf("%lld%lld%lld%lld",&p,&a,&b,&c);
	t1=(a-p%a)%a;
	t2=(b-p%b)%b;
	t3=(c-p%c)%c;
	ans=min(t1,t2);
	ans=min(ans,t3);
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
