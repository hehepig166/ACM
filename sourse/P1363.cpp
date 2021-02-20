#include <cstdio>
#include <cstring>
using namespace std;
int n,m,si,sj,vis[1505][1505][3],GG;
int fx[4][2]={{0,1},{1,0},{0,-1},{-1,0}};
char a[1501][1501],tmp;

char du(){
	scanf("%c",&tmp);
	while (tmp!='.' && tmp!='#' && tmp!='S')
		scanf("%c",&tmp);
	return tmp;
}

void dfs(int x,int y){
	int xx,yy,lxx,lyy;
	xx=((x)%n+n)%n;
	yy=((y)%m+m)%m;
	vis[xx][yy][0]=x,vis[xx][yy][1]=y,vis[xx][yy][2]=1;
	for (int i=0; i<4; i++){
		if (GG) return;
		lxx=x+fx[i][0];
		lyy=y+fx[i][1];
		xx=((lxx)%n+n)%n;
		yy=((lyy)%m+m)%m;
		if (!vis[xx][yy][2] && a[xx][yy]=='.') dfs(lxx,lyy);
		if (vis[xx][yy][2] && (vis[xx][yy][0]!=lxx || vis[xx][yy][1]!=lyy)){
			GG=1;
			return;
		}
	}
	return;
}

int main(){
	while (scanf("%d%d",&n,&m)!=EOF){
		GG=0;
		memset(vis,0,sizeof(vis));
		memset(a,0,sizeof(a));
		for (int i=0; i<n; i++){
			for (int j=0; j<m; j++){
				a[i][j]=du();
				if (a[i][j]=='S') si=i,sj=j;
			}
		}
		dfs(si,sj);
		if (GG) printf("Yes\n"); else printf("No\n");
	}
}

/*
5 4
##.#
##S#
#..#
#.##
#..#
5 4
##.#
##S#
#..#
..#.
#.##

*/
