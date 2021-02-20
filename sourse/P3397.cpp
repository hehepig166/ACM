#include <cstdio>
int n,m,a[2000][2000],b[2000][2000];

int main()
{
	scanf("%d%d",&n,&m);
	for (int k=1,x1,x2,y1,y2; k<=m; k++){
		scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
		for (int i=x1; i<=x2; i++)
			a[i][y1]++,a[i][y2+1]--;
	}
	
	for (int i=1; i<=n; i++){
		b[i][0]=0;
		for (int j=1; j<=n; j++)
			b[i][j]=b[i][j-1]+a[i][j];
	}
	
	for (int i=1; i<=n; i++){
		for (int j=1; j<=n; j++)
			printf("%d ",b[i][j]);
		puts("");
	}
	return 0;
}
