#include <cstdio>
#include <algorithm>
using namespace std;
long long i,n,c,cnt,ans,C,a[100005];

int main(){
	scanf("%lld",&n);
	ans=-n;
	for (i=1; i<=n; i++) scanf("%lld",&a[i]),ans+=a[i];
	sort(a+1,a+n+1);
	for (c=1; c<=1000000; c++){
		cnt=0;
		for (i=1,C=1; i<=n; i++,C*=c){
			if (C>a[i]) cnt+=C-a[i]; else cnt+=a[i]-C;
			if (cnt>=ans) break;
		}
		if (cnt<ans) ans=cnt;
	}
	printf("%lld",ans);
}
