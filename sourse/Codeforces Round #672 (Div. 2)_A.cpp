#include <cstdio>
#include <algorithm>
#include <cmath>
using namespace std;
long long T,n,a[500005],b[500005],ans;
bool cmp(int x,int y){return a[x]<a[y];}

int main()
{
	scanf("%lld",&T);
	while (T--)
	{
		scanf("%lld",&n);
		ans=0;
		for (long long i=1; i<=n; i++)
		{
			scanf("%lld",&a[i]);
		}
		for (int i=1; i<n; i++)
			if (a[i]<=a[i+1])
				ans=1;
		
		if (ans) printf("YES\n");
		else printf("NO\n");
	}
	return 0;
}
