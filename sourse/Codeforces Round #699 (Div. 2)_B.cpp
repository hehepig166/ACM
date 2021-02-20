#include <bits/stdc++.h>
using namespace std;

void solve()
{
	long long n,k;
	long long h[105];
	scanf("%lld%lld",&n,&k);
	for (int i=1; i<=n; i++)
		scanf("%lld",&h[i]);
	
	h[0]=0;
	
	for (int i=1; i<=n; i++)
	{
		if (i==n)
		{
			puts("-1");
			return;
		}
		if (h[i]>=h[i+1])
		{
			continue;
		}
		else
		{
			while (h[i]<h[i+1])
			{
				int j,ss;
				for (j=i; j && h[j]==h[i]; j--)
					;
				if (j==0 || h[j]>h[i+1])
				{
					ss=h[i+1];
				}
				else
				{
					ss=h[j];
				}
				int tmp=(i-j)*(ss-h[i]);
				if (tmp<k)
				{
					for (int l=j+1; l<=i; l++)
							h[l]=ss;
				k-=tmp;
					continue;
				}
				else
				{
					k=(k-1)%(i-j);
					printf("%d\n",i-k);
					return;
					
				}
			}
		}
	}
	puts("-1");
	return;
}

int main()
{
	int T;
	scanf("%d",&T);
	while (T--)
	{
		solve();
	}
	return 0;
}
