#include <cstdio>
#define Ha 1000007
int n,m,a[200],dp[200][200];
//dp[x][y]	��ǰx�ֻ���y�跽���� 

int main()
{
	scanf("%d%d",&n,&m);
	for (int i=1; i<=n; i++)
		scanf("%d",&a[i]);
	dp[0][0]=1;
	for (int x=1; x<=n; x++)				//ǰx�ֻ� 
		for (int y=0; y<=m; y++)			//��y�� 
			for (int i=0; i<=a[x]; i++)		//��x�ֻ���i��
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
