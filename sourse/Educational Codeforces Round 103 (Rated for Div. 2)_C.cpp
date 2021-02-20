#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
LL T,n,ans,lst;
LL a[100005],b[100005],c[100005];
//LL a[100],b[100],c[100];

int main()
{
	LL T;
	scanf("%lld",&T);
	while (T--) {
		scanf("%lld",&n);
		for (int i=1; i<=n; i++) scanf("%lld",&c[i]);
		for (int i=1; i<=n; i++) scanf("%lld",&a[i]);
		for (int i=1; i<=n; i++) scanf("%lld",&b[i]);
		
		ans=1;
		lst=c[n];
		for (int i=n-1; i>0; i--) {
			if (a[i+1]==b[i+1]) {
				ans=max(ans,lst+1);
				lst=c[i];
				continue;
			}
			ans=max(ans,lst+abs(a[i+1]-b[i+1])+1);
			lst=c[i]+max(lst-(abs(a[i+1]-b[i+1])-1),0ll);
		}
		
		printf("%lld\n",ans);
	}
	return 0;
}
