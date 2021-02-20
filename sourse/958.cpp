#include <cstdio>
#include <cstring>
#define Ha 12345678
using namespace std;
int n,m,T,O,ans,a[10][10],f[100];
char A[10][10],ch;
bool gg(int x,int y){
	int kkk=x>y;
	return x>y;
}

bool check(){
	for (int i=1; i<=n; i++)
		for (int j=1; j<=m; j++) if (A[i][j]=='X')
			if (gg(a[i][j],a[i][j-1]) || gg(a[i][j],a[i][j+1]) || gg(a[i][j],a[i-1][j]) || gg(a[i][j],a[i-1][j-1]) || gg(a[i][j],a[i-1][j+1]) || gg(a[i][j],a[i+1][j]) || gg(a[i][j],a[i+1][j-1]) || gg(a[i][j],a[i+1][j+1])) return 0;
	return 1;
}

void dfs(int x,int y){
	if (x>n){
		if (check())
			ans++;
		if (ans>Ha) ans-=Ha;
		return ;
	}
	int xx=x,yy=y+1;
	if (yy>m) xx=xx+1,yy=1;
	for (int i=1; i<=O; i++) if (!f[i]){
		a[x][y]=f[i]=i;
		dfs(xx,yy);
		f[i]=0;
	}
}

int main(){
	freopen("1.txt","r",stdin);
	if (n*m>50) return 0;
	for (scanf("%d",&T); T--;){
		memset(a,0x7f,sizeof(a));
		ans=0;
		scanf("%d%d",&n,&m);
		O=n*m;
		for (int i=1; i<=n; i++)
			for (int j=1; j<=m; j++){
				while (ch!='.'&&ch!='X') ch=getchar();
				A[i][j]=ch;
				ch=getchar();
			}
		dfs(1,1);
		printf("%d\n",ans);
	}
}

