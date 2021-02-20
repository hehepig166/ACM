#include <bits/stdc++.h>
using namespace std;

long long T,n,d[300005],s,fail,N,lst;

int main()
{
	scanf("%lld",&T);
	while (T--) {
		scanf("%lld",&n);
		N=n<<1;
		for (long long i=1; i<=N; i++) {
			scanf("%lld",&d[i]);
		}
		sort(d+1,d+N+1);
		
		s=0;
		fail=0;
		lst=-1;
		
		for (long long i=N-2; i>0; i-=2) {
			if (d[i]==d[i+1]) {
				fail=1;
			}
		}
		
		for (long long i=N; i>0 && !fail; i-=2) {
			if (d[i]!=d[i-1]) {
				fail=1;
				break;
			}
			if ((d[i]-s)%(i)!=0 || (d[i]-s)<=0 || (lst==((d[i]-s)/(i)))) {
				fail=1;
				break;
			}
			lst=(d[i]-s)/(i);
			s+=(d[i]-s)/(i)*2;
		}
		
		puts(fail ? "NO" : "YES");
	}
	return 0;
}
