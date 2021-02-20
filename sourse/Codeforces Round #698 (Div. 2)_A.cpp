#include <bits/stdc++.h>
using namespace std;
int T,n,f[200],a,ans=0;

int main()
{
	scanf("%d",&T);
	while (T--) {
		ans=0;
		memset(f,0,sizeof(f));
		scanf("%d",&n);
		for (int i=1; i<=n; i++) {
			scanf("%d",&a);
			f[a]++;
			if (f[a]>ans) {
				ans=f[a];
			}
		}
		printf("%d\n",ans);
	}
	
	return 0;
}
