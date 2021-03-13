#include <bits/stdc++.h>
using namespace std;
#define N 105

long long n,a[N],b[N],tt[N];

void solve()
{
	long long tmp;
	scanf("%lld",&n);
	for (int i=1; i<=n; i++)
		scanf("%lld%lld",&a[i],&b[i]);
	for (int i=1; i<=n; i++)
		scanf("%lld",&tt[i]);
	
	long long t=0;
	for (int i=1; i<n; i++)
	{
		tmp=t+a[i]-b[i-1]+tt[i]+(b[i]-a[i]+1)/2;
		t=max(tmp,b[i]);
	}
	
	t+=a[n]-b[n-1]+tt[n];
	
	printf("%lld\n",t);
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
