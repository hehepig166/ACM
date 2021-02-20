#include <cstdio>

int main()
{
	int T,n,k,m;
	scanf("%d",&T);
	while (T--) {
		scanf("%d%d",&n,&k);
		m=k+k-n;
		for (int i=1; i<m; i++) {
			printf("%d ",i);
		}
		for (int i=k; i>=m; i--) {
			printf("%d ",i);
		}
		puts("");
	}
	return 0;
}
