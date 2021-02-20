#include <bits/stdc++.h>
using namespace std;
int n;
char s[300005];
long long L[300005],R[300005],ans[300005];

int main()
{
	int T;
	scanf("%d",&T);
	while (T--) {
		scanf("%d%s",&n,s+1);
		
		L[1]=1;
		for (int i=2; i<=n; i++) {
			if (s[i]!=s[i-1]) {
				L[i]=L[i-1]+1;
			}
			else {
				L[i]=1;
			}
		}
		
		R[n]=1;
		for (int i=n-1; i>=1; i--) {
			if (s[i]!=s[i+1]) {
				R[i]=R[i+1]+1;
			}
			else {
				R[i]=1;
			}
		}
		
		ans[0]=(s[1]=='R') ? R[1] : 0;
		ans[n]=(s[n]=='L') ? L[n] : 0;
		for (int i=1; i<n; i++) {
			ans[i]=(s[i]=='L' ? L[i] : 0) + (s[i+1]=='R' ? R[i+1] : 0);
		}
		
		for (int i=0; i<=n; i++) {
			printf("%lld ",ans[i]+1);
		}
		puts("");
	}
	return 0;
}
