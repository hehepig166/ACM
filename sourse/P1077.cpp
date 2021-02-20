#include <cstdio>
#define Ha 1000007
int n,m,a[200],dp[200][200];
//dp[x][y]	用前x种花种y盆方案数 

int main()
{
	scanf("%d%d",&n,&m);
	for (int i=1; i<=n; i++)
		scanf("%d",&a[i]);
	dp[0][0]=1;
	for (int x=1; x<=n; x++)				//前x种花 
		for (int y=0; y<=m; y++)			//种y盆 
			for (int i=0; i<=a[x]; i++)		//第x种花种i盆
			{
				if (i>y) break;
				dp[x][y]=(dp[x][y]+dp[x-1][y-i])%Ha;
			}
	printf("%d",dp[n][m]);
	return 0;
}

/*
3 5
3 4 4

*/
