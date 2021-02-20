#include <cstdio>
int cnt,T,n,m,a[105][105],b[50005][10];
char ch;

int main()
{
	scanf("%d",&T);
	while (T--)
	{
		cnt=0;
		scanf("%d%d",&n,&m);
		if (T==0)
		{
			int asa=1;
		}
		for (int i=1; i<=n; i++)
		{
			for (ch=getchar(); ch!='0' && ch!='1'; ch=getchar());
			for (int j=1; j<=m; j++)
			{
				a[i][j]=ch-'0';
				ch=getchar();
			}
		}
		
		for (int i=1; i<=n; i++)
			for (int j=1; j<=m; j++)
			{
				if (a[i][j]==1)
				{
					cnt++;
					b[cnt][0]=i;
					b[cnt][1]=j;
				}
			}
		printf("%d\n",cnt*3);
		for (int i=1,X,Y; i<=cnt; i++)
		{
			X=b[i][0];
			Y=b[i][1];
			if (X<n && Y<m)
			{
				printf("%d %d %d %d %d %d\n",X,Y,X+1,Y,X+1,Y+1);
				printf("%d %d %d %d %d %d\n",X,Y,X,Y+1,X+1,Y+1);
				printf("%d %d %d %d %d %d\n",X,Y,X+1,Y,X,Y+1);
				continue;
			}
			if (X<n && Y==m)
			{
				printf("%d %d %d %d %d %d\n",X,Y,X+1,Y,X,Y-1);
				printf("%d %d %d %d %d %d\n",X,Y,X,Y-1,X+1,Y-1);
				printf("%d %d %d %d %d %d\n",X,Y,X+1,Y,X+1,Y-1);
				continue;
			}
			if (X==n && Y<m)
			{
				printf("%d %d %d %d %d %d\n",X,Y,X-1,Y,X,Y+1);
				printf("%d %d %d %d %d %d\n",X,Y,X-1,Y+1,X,Y+1);
				printf("%d %d %d %d %d %d\n",X,Y,X-1,Y,X-1,Y+1);
				continue;
			}
			if (X==n && Y==m)
			{
				printf("%d %d %d %d %d %d\n",X,Y,X-1,Y,X,Y-1);
				printf("%d %d %d %d %d %d\n",X,Y,X-1,Y,X-1,Y-1);
				printf("%d %d %d %d %d %d\n",X,Y,X-1,Y-1,X,Y-1);
				continue;
			}
		}
	}
	return 0;
}
