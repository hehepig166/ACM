#include <cstdio>
int T,n,m,ROW[510][510],COL[510][510],nr[250005],first_col;

int main()
{
	scanf("%d",&T);
	while (T--)
	{
		scanf("%d%d",&n,&m);
		for (int i=1; i<=n; i++)
		{
			for (int j=1; j<=m; j++)
				scanf("%d",&ROW[i][j]);
			nr[ROW[i][1]]=i;
		}
		for (int i=1; i<=m; i++)
			for (int j=1; j<=n; j++)
			{
				scanf("%d",&COL[i][j]);
				if (ROW[1][1]==COL[i][j])
					first_col=i;
			}
		
		for (int i=1; i<=n; i++)
		{
			for (int j=1; j<=m; j++)
				printf("%d ",ROW[nr[COL[first_col][i]]][j]);
			printf("\n");
		}
	}
	return 0;
}
