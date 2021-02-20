#include <cstdio>
int L[3500][3500],R[3500][3500],a[3500],n,t;
long long ans;

int main(){
	for(scanf("%d",&t); t; t--){
		ans=0;
		scanf("%d",&n);
		for (int i=1; i<=n; i++) scanf("%d",&a[i]);
		for (int i=1; i<=n; i++){
			for (int j=1; j<=n; j++) L[j][i]=L[j][i-1];
			L[a[i]][i]=L[a[i]][i-1]+1;
		}
		for (int i=n; i; i--){
			for (int j=1; j<=n; j++) R[j][i]=R[j][i+1];
			R[a[i]][i]=R[a[i]][i+1]+1;
		}
		for (int j=1; j<n; j++)
			for (int k=j+1; k<n; k++)
				ans=ans+(long long)L[a[k]][j-1]*R[a[j]][k+1];
		printf("%lld\n",ans);
	}
}

/*
L[a][b] [1,b]中 a 的个数 
R[a][b] [b,n]中 a 的个数 
*/
