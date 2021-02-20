#include <cstdio>
int n,m,tp,a[4000][4000],st[4000],L[3001][3001],R[3001][3001],D[3001][3001],U[3001][3001];
long long tmp,ans;

void rd(int &x){
	char ch;
	for (ch=getchar(); ch<'0' || ch>'9'; ) ch=getchar();
	while (ch>='0' && ch<='9') x=(x<<3)+(x<<1)+ch-'0', ch=getchar();
}

int main(){
	scanf("%d%d",&n,&m);
	for (int i=1; i<=n; i++)
		for (int j=1; j<=m; j++) rd(a[i][j]);
	
	/*
	for (int i=1; i<=n; i++)
		for (int j=1; j<=m; j++)
			slr[i][j]=slr[i][j-1]+a[i][j];
	for (int i=1; i<=m; i++)
		for (int j=1; j<=n; j++)
			sud[j][i]=sud[j-1][i]+a[j][i];
			
	*/
	//Íù×ó×îÔ¶
	for (int i=1; i<=n; i++){
		L[i][1]=st[tp=1]=1;
		for (int j=2; j<=m; j++){
			st[++tp]=j;
			while (a[i][j]<=a[i][st[tp-1]] && tp) tp--;
			L[i][j]=st[tp];
			st[++tp]=j;
		}
	}
	//ÍùÓÒ×îÔ¶
	for (int i=1; i<=n; i++) {
		R[i][m]=st[tp=1]=m;
		for (int j=m-1; j; j--){
			st[++tp]=j;
			while (a[i][j]<=a[i][st[tp-1]] && tp) tp--;
			R[i][j]=st[tp];
			st[++tp]=j;
		}
	}
	//ÍùÏÂ×îÔ¶ 
	for (int i=1; i<=m; i++) {
		D[n][i]=st[tp=1]=n;
		for (int j=n-1; j; j--){
			st[++tp]=j;
			while (a[j][i]<=a[st[tp-1]][i] && tp) tp--;
			D[j][i]=st[tp];
			st[++tp]=j;
		}
	}
	//ÍùÉÏ×îÔ¶ 
	for (int i=1; i<=m; i++) {
		U[1][i]=st[tp=1]=1;
		for (int j=2; j<=n; j++){
			st[++tp]=j;
			while (a[j][i]<=a[st[tp-1]][i] && tp) tp--;
			U[j][i]=st[tp];
			st[++tp]=j;
		}
	}
	for (int i=1; i<=n; i++)
		for (int j=1; j<=m; j++){
			tmp=(long long)R[i][j]-L[i][j]+1+D[i][j]-U[i][j];
			tmp=tmp*a[i][j];
			if (ans<tmp) ans=tmp;
		}
	printf("%lld",ans);
}

/*
5 7
1 3 3 2 5 1 2
2 1 2 3 6 1 3
9 3 2 3 6 5 4
1 1 2 1 3 5 7
3 2 1 2 1 2 3
*/
