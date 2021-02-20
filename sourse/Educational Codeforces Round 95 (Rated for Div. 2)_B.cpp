#include <cstdio>
#include <algorithm>
using namespace std;
int a[200],b[200],f[200],cnt,T,n;

int main(){
	scanf("%d",&T);
	while (T--){
		scanf("%d",&n);
		for (int i=1; i<=n; i++) scanf("%d",&a[i]);
		for (int i=1; i<=n; i++) scanf("%d",&f[i]);
		for (int i=1; i<=n; i++) if (!f[i]) b[++cnt]=a[i];
		sort(b+1,b+cnt+1);
		for (int i=1; i<=n; i++) printf("%d ",f[i] ? a[i] : b[cnt--]);
		printf("\n");
	}
}
