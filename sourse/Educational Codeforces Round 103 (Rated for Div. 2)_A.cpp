#include <bits/stdc++.h>
using namespace std;

int main()
{
	long long T,t1,n,k;
	scanf("%lld",&T);
	while (T--) {
		scanf("%lld%lld",&n,&k);
		if (n==k) {
			puts("1");
			continue;
		}
		else if (n<k) {
			printf("%lld\n",k/n+(k%n!=0));
		}
		else {
			puts(n%k==0 ? "1" : "2");
		}
		
	}
	return 0;
}
