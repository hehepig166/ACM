#include <cstdio>
#include <algorithm>
using namespace std;
struct he{int l,r;}a[1000005];
bool cmp(he x, he y){return x.r<y.r;}
int n,ans;

int main(){
	scanf("%d",&n);
	for (int i=1; i<=n; i++) scanf("%d%d",&a[i].l,&a[i].r);
	sort(a+1,a+n+1,cmp);
	for (int i=1,R=0; i<=n; i++){
		if (a[i].l>=R){
			ans++;
			R=a[i].r;
		}
	}
	printf("%d",ans);
}
