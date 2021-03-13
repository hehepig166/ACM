#include <bits/stdc++.h>
using namespace std;
int n,u,v,a[1000005];

void solve()
{
	scanf("%d%d%d",&n,&u,&v);
	for (int i=1; i<=n; i++) scanf("%d",&a[i]);
	
	int f[2]={0};
	
	for (int i=2; i<=n; i++)
	{
		if (abs(a[i-1]-a[i])>1)
		{
			puts("0");
			return;
		}
		else
		{
			f[abs(a[i-1]-a[i])]++;
		}
	}
	
	long long ans;
	ans= f[1] ? min(u,v) : min(u+v,v+v);
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
