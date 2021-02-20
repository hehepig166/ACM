#include <cstdio>
#define Ha 998244353
typedef long long ll;

ll N,P,a[1000005],ans=1;

ll ksm(ll x,ll n)
{
	ll ret=1;
	for (ll i=1,tmp=x; n; ) {
		if (n&i) {
			ret=ret*tmp%Ha;
			n^=i;
		}
		tmp=tmp*tmp%Ha;
		i<<=1;
	}
	return ret;
}

int main()
{
	scanf("%lld%lld",&N,&P);
	for (int i=1; i<=N; i++) {
		scanf("%lld",&a[i]);
		ans=ans*(ksm(P,a[i])+1)%Ha;
	}
	
	printf("%lld",ans);
	
	return 0;
}
