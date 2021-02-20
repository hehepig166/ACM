#include <cstdio>
#include <iostream>
using namespace std;
long long n,a[200005],dp[200005][2];

int main()
{
	freopen("1.txt","r",stdin);
	scanf("%lld",&n);
	for (int i=1; i<=n; i++)
		scanf("%lld",&a[i]);
	dp[1][0]=dp[1][1]=a[1];
	for (int i=2; i<=n; i++)
	{
		dp[i][0]=max(dp[i-1][0],dp[i-1][1]);
		dp[i][1]=max(a[i],dp[i-1][1]+a[i]);
	}
	printf("%lld",max(dp[n][0],dp[n][1]));
	
	return 0;
}
/*
dp[i][0]	不选a[i]前 i 个最大连续和 
dp[i][1] 	选a[i]前 i 个最大连续和 
*/
