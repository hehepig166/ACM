#include <cstdio>
long long T,X,Y,K,a,b,ans;

int main(){
	scanf("%lld",&T);
	while (T--){
		scanf("%lld%lld%lld",&X,&Y,&K);
		ans=0;
		X--;
		a=K+K*Y-1;
		if (a%X==0) ans+=a/X; else ans+=a/X+1;
 		ans+=K;
		printf("%lld\n",ans);
	}
}
