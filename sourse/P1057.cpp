#include <cstdio>
int dp[50][50],n,m;

int main()
{
	scanf("%d%d",&n,&m);
	dp[0][0]=1;
	for (int i=0; i<m; i++)	//´«µÚi´Î 
		for (int j=0; j<n; j++)
		{
			dp[i+1][(j+1)%n]+=dp[i][j];
			dp[i+1][(j-1+n)%n]+=dp[i][j];
		}
	printf("%d",dp[m][0]);
	return 0;
}

