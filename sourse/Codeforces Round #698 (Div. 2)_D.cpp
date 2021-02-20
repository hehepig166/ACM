#include <bits/stdc++.h>
using namespace std;
long long T,n,k,gg,a[200005];

long long my_gcd(long long b, long long c) {
	return c ? my_gcd(c,b%c) : b;
}

int main()
{	
	scanf("%lld",&T);
	while (T--) {
		scanf("%lld%lld",&n,&k);
		gg=0;
		for (int i=1; i<=n; i++) {
			scanf("%lld",&a[i]);
			gg|=(a[i]==k);
		}
		
		sort(a+1,a+n+1);
		long long tmp=a[2]-a[1];
		
		for (int i=3; i<=n; i++) {
			tmp=my_gcd(tmp,a[i]-a[i-1]);
		}
		
		gg|=((k-a[1])%tmp==0);
		puts(gg ? "YES" : "NO");
	}
	return 0;
}
