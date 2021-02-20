#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;
long long T,n,q,ans,a[300005],dp[300005][2];
//dp[i][0]	到i且上一个符号为-的最大值
//dp[i][1]	到i且上一个符号为+的最大值 

int main()
{
	scanf("%lld",&T);
	while (T--)
	{
		scanf("%lld%lld",&n,&q);
		for (int i=1; i<=n; i++)
			scanf("%lld",&a[i]);
		for (int i=1; i<=q; i++)
			scanf("%lld%lld",&L[i],&R[i]);
		for (int i=1; i<=n; i++)
		{
			dp[i][0]=max(dp[i-1][0],dp[i-1][1]-a[i]);
			dp[i][1]=max(dp[i-1][1],dp[i-1][0]+a[i]);
		}
		ans=max(dp[n][1],dp[n][0]);
		printf("%lld\n",ans);
	}
}
