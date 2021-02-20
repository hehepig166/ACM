#include <cstdio>
#define chg(x,y) a[x][y]=(a[x][y]+1)%2
int cnt,T,n,m,a[105][105];
char ch;

struct node
{
	int x,y;
	node()
	{
		x=0,y=0;
	}
	node(int xx, int yy)
	{
		x=xx;
		y=yy;
	}
	
	void show()
	{
		printf("%d %d ",x,y);
	}
	
} b[50005][3];

int dfs(int X,int Y,int dep)
{
	if (a[X][Y]==0 && a[X+1][Y+1]==0 && a[X+1][Y]==0 && a[X][Y+1]==0)
		return 1;
	if (dep==4)
		return 0;
	cnt++;
	
	b[cnt][0]=node(X,Y);
	chg(X,Y);
	b[cnt][1]=node(X,Y+1);
	chg(X,Y+1);
	b[cnt][2]=node(X+1,Y);
	chg(X+1,Y);
	if (dfs(X,Y,dep+1))
		return 1;
	
	chg(X,Y+1);
	b[cnt][1]=node(X+1,Y+1);
	chg(X+1,Y+1);
	if (dfs(X,Y,dep+1))
		return 1;
		
	chg(X+1,Y);
	b[cnt][2]=node(X,Y+1);
	chg(X,Y+1);
	if (dfs(X,Y,dep+1))
		return 1;
	
	chg(X,Y);
	b[cnt][0]=node(X+1,Y);
	chg(X+1,Y);
	if (dfs(X,Y,dep+1))
		return 1;
	
	chg(X+1,Y);
	chg(X,Y+1);
	chg(X+1,Y+1);
	cnt--;
	return 0;
}

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
		
		if (n%2==1)
		{
			for (int i=1; i<m; i++)
				if (a[n][i]==1)
				{
					cnt++;
					b[cnt][0]=node(n,i);
						a[n][i]=(a[n][i]+1)%2;
					b[cnt][1]=node(n,i+1);
						a[n][i+1]=(a[n][i+1]+1)%2;
					b[cnt][2]=node(n-1,i);
						a[n-1][i]=(a[n-1][i]+1)%2;
				}
		}
		if (m%2==1)
		{
			for (int i=1; i<n; i++)
				if (a[i][m]==1)
				{
					cnt++;
					b[cnt][0]=node(i,m);
						a[i][m]=(a[i][m]+1)%2;
					b[cnt][1]=node(i+1,m);
						a[i+1][m]=(a[i+1][m]+1)%2;
					b[cnt][2]=node(i,m-1);
						a[i][m-1]=(a[i][m-1]+1)%2;
				}
		}
		if (a[n][m]==1 && (n%2 || m%2))
		{
			cnt++;
			b[cnt][0]=node(n,m);
				chg(n,m);
			b[cnt][1]=node(n-1,m);
				chg(n-1,m);
			b[cnt][2]=node(n,m-1);
				chg(n,m-1);
			
			cnt++;
			b[cnt][0]=node(n-1,m-1);
				chg(n-1,m-1);
			b[cnt][1]=node(n-1,m);
				chg(n-1,m);
			b[cnt][2]=node(n,m-1);
				chg(n,m-1);
		}
		
		for (int i=1; i<=n; i+=2)
			for (int j=1; j<=m; j+=2)
			{
				dfs(i,j,0);
			}
		
		printf("%d\n",cnt);
		for (int i=1; i<=cnt; i++)
		{
			b[i][0].show();
			b[i][1].show();
			b[i][2].show();
			printf("\n");
		}
	}
	return 0;
}

/*
5
4 4
1111
0110
0110
1111
*/
