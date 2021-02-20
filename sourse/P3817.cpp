#include <cstdio>
long long ans,n,x,a[10000000];

int main(){
	scanf("%lld%lld",&n,&x);
	for (int i=1; i<=n; i++) scanf("%lld",&a[i]);
	for (int i=2,tmp; i<=n; i++){
		if (a[i-1]+a[i]>x){
			tmp=a[i-1]+a[i]-x;
			a[i]-=tmp;
			ans+=tmp;
		}
	}
	printf("%lld",ans);
}
