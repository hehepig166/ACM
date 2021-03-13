#include <bits/stdc++.h>
using namespace std;

int n,a[200005],f[200005];

void solve()
{
	scanf("%d",&n);
	for (int i=1; i<=n; i++)
	{
		f[i]=0;
		scanf("%d",&a[i]);
	}
	
	int cnt=0;
	for (int i=n; i>0; i--)
	{
		cnt=max(cnt,a[i]);
		f[i]= (cnt>0);
		cnt--;
	}
	
	for (int i=1; i<=n; i++)
		printf("%d ",f[i]);
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
