#include <cstdio>
int t,n,p[500],q[500],c[500],f;


int main(){
	scanf("%d",&t);
	while (t--){
		scanf("%d",&n);
		for (int i=1; i<=n; i++) scanf("%d",&p[i]);
		for (int i=n; i; i--) printf("%d ",p[i]);
		printf("\n");
	}
}
