#include <cstdio>
#include <algorithm>
using namespace std;

int main()
{
	int n,d,T;
	int a[200];
	scanf("%d",&T);
	while (T--) {
		scanf("%d%d",&n,&d);
		for (int i=1; i<=n; i++) {
			scanf("%d",&a[i]);
		}
		sort(a+1,a+n+1);
		printf((a[1]+a[2]<=d || a[n]<=d) ? "YES\n" : "NO\n");
	}
	return 0;
}
