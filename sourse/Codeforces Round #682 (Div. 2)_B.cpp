#include <cstdio>
#include <algorithm>
using namespace std;
int T,n,ans,a[1005];

int main()
{
	scanf("%d",&T);
	while (T--)
	{
		ans=0;
		scanf("%d",&n);
		for (int i=1; i<=n; i++)
			scanf("%d",&a[i]);
		sort(a+1,a+n+1);
		for (int i=1; i<n; i++)
			ans+=(a[i]==a[i+1]);
		printf(ans>0 ? "YES\n" : "NO\n");
	}
	return 0;
}
