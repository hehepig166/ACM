#include <bits/stdc++.h>
using namespace std;
long long T,q,d,a,A,fail,tmp;

int main()
{
	scanf("%lld",&T);
	while (T--) {
		scanf("%lld%lld",&q,&d);
		while (q--) {
			scanf("%lld",&A);
			if (A>=d*10) {
				puts("YES");
				continue;
			}
			if (A%10==d || A/10==d) {
				puts("YES");
				continue;
			}
			fail=1;
			for (int i=1; i<10; i++) {
				if (i*d>A) {
					break;
				}
				if (i*d%10 == A%10) {
					fail=0;
					break;
				}
			}
			puts(fail ? "NO" : "YES");
		}
	}
	return 0;
}
