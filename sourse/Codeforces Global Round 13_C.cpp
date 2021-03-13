#include <bits/stdc++.h>
using namespace std;
int n;
int a[5005],b[5005];

void solve()
{
	scanf("%d",&n);
	for (int i=1; i<=n; i++) scanf("%d",&a[i]);
	int L=1,p,tp;
	long long ans=0;
	for (int i=1; i<=n; i++) b[i]=i+1;
	while (L<n)
	{
		if (a[L]==1)
		{
			L++;
			continue;
		}
		if (L+a[L]>n)
		{
			ans+=a[L]-n+L;
			a[L]=n-L;
		}
		while (a[L]!=1)
		{
			ans++;
			for (p=L; p<=n; )
			{
				if (a[p]==1)
				{
					tp=p+1;
					while (tp<=n && a[tp]==1) tp=b[tp];
					for (; p<tp; p=b[p])
						b[p]=tp;
				}
				else
				{
					a[p]--;
					p+=a[p]+1;
				}
			}
		}
		
		L++;
	}
	ans+=a[n]-1;
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
