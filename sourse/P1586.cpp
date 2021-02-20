#include <cstdio>
int n,T,dp[250][32770][5],ans;
//dp[i][j][k]	用前i个平方数凑出j的方案数,用k个数 

int main()
{
	dp[0][0][0]=1;
	for (int i=1; i<=200; i++)
		for (int j=0; j<=32768; j++)
		{
			if (i*i*4<j) break;
			for (int k=0; k<=4; k++)
				for (int kk=0; kk<=k && j-kk*i*i>=0; kk++)
					dp[i][j][k]+=dp[i-1][j-kk*i*i][k-kk];
		}
	scanf("%d",&T);
	while (T--)
	{
		scanf("%d",&n);
		ans=dp[200][n][0]+dp[200][n][1]+dp[200][n][2]+dp[200][n][3]+dp[200][n][4];
		printf("%d\n",ans);
	}
}
