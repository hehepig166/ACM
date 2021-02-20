#include <bits/stdc++.h>
using namespace std;

int n,k;
long long p[105],ans;


int main()
{
	int T;
	scanf("%d",&T);
	while (T--) {
		scanf("%d%d",&n,&k);
		for (int i=1; i<=n; i++) {
			scanf("%lld",&p[i]);
		}
		
		long long tsum=p[1],tmp;
		
		ans=0;
		for (int i=2; i<=n; i++) {
			tmp=100.0*p[i]/k;
			tmp+=(tmp*k<100*p[i]);
			ans=max(ans,tmp-tsum);
			tsum+=p[i];
		}
		
		printf("%lld\n",ans);
	}
	return 0;
}
