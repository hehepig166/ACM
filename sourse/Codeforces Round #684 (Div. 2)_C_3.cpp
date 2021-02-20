#include <cstdio>
int cnt,T,n,m,a[105][105],b[50000][10];
char ch;

int main()
{
	scanf("%d",&T);
	while (T--)
	{
		cnt=0;
		scanf("%d%d",&n,&m);
		for (int i=1; i<=n; i++)
		{
			for (ch=getchar(); ch!='0' && ch!='1'; ch=getchar());
			for (int j=1; j<=m; j++)
			{
				a[i][j]=ch-'0';
				ch=getchar();
			}
		}
		
		for (int j=2; j<=m; j+=2)
		{
			int i;
			for (i=1; i<n; i++)
			{
				if (a[i][j-1]==0 && a[i][j]==0)
					continue;
					
				if (a[i][j-1]==0 && a[i][j]==1)
				{
					cnt++;
					b[cnt][0]=i;
					b[cnt][1]=j;
					a[i][j]=a[i][j]^1;
					
					b[cnt][2]=i+1;
					b[cnt][3]=j+1;
					a[i+1][j+1]=a[i+1][j+1]^1;
					
					b[cnt][4]=i+1;
					b[cnt][5]=j;
					a[i+1][j]=a[i+1][j]^1;
				}
				if (a[i][j-1]==1 && a[i][j]==0)
				{
					cnt++;
					b[cnt][0]=i;
					b[cnt][1]=j-1;
					a[i][j-1]=a[i][j-1]^1;
					
					c[cnt][2]=i+1;
					c[cnt][3]=j-1;
					a[i+1][j-1]=a[i+1][j-1]^1;
					
					c[cnt][4]=i+1;
					c[cnt][5]=j;
					a[i+1][j]=a[i+1][j]^1;
				}
				
				if (a[i][j-1]==1 && a[i][j]==1)
				{
					cnt++;
					b[cnt][0]=i;
					b[cnt][1]=j-1;
					a[i][j-1]=a[i][j-1]^1;
					
					b[cnt][2]=i;
					b[cnt][3]=j;
					a[i][j]=a[i][j]^1;
					
					b[cnt][4]=i+1;
					b[cnt][5]=j;
					a[i+1][j]=a[i+1][j]^1;
				}
			}
			
			
		}
	}
	return 0;
}
