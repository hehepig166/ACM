#include <cstdio>
int dp[3000][3000],n,k,ans=0;
//dp[i][j]	i位且最大位为j的数列个数 

int main()
{
	scanf("%d%d",&k,&n);
	for (int i=1; i<=k; i++)
		dp[1][i]=1;
	for (int i=1; i<n; i++)
		for (int j=1; j<=k; j++)
			for (int p=1; ; p++)
			{
				if (j*p>k)
					break;
				dp[i+1][j*p]=(dp[i+1][j*p]+dp[i][j])%1000000007;
			}
	for (int i=1; i<=k; i++)
		ans=(ans+dp[n][i])%1000000007;
	printf("%d",ans);
	return 0;
}
