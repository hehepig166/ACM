#include <bits/stdc++.h>
using namespace std;

int n,m,a[100005],b[100005],c[100005],ans[100005];
stack<int> s[100005];

void solve() {
	scanf("%d%d",&n,&m);
	for (int i=1; i<=n; i++) {
		s[i]=stack<int>();
	}
	for (int i=1; i<=n; i++) {
		scanf("%d",&a[i]);
	}
	for (int i=1; i<=n; i++) {
		scanf("%d",&b[i]);
		if (a[i]!=b[i]) {
			s[b[i]].push(i);
		}
	}
	for (int i=1; i<=m; i++) {
		scanf("%d",&c[i]);
	}
	
	int ok=0;
	if (s[c[m]].empty()) {
		for (int i=1; i<=n; i++) {
			if (b[i]==c[m]) {
				ok=i;
				break;
			}
		}
	}
	else {
		ok=s[c[m]].top();
		s[c[m]].pop();
	}
	
	if (!ok) {
		puts("NO");
		return;
	}
	
	ans[m]=ok;
	for (int i=1; i<m; i++) {
		if (s[c[i]].empty()) {
			ans[i]=ok;
		}
		else {
			ans[i]=s[c[i]].top();
			s[c[i]].pop();
		}
	}
	
	for (int i=1; i<=n; i++) {
		if (!s[i].empty()) {
			puts("NO");
			return;
		}
	}
	puts("YES");
	for (int i=1; i<=m; i++) {
		printf("%d ",ans[i]);
	}
	puts("");
}

int main() {
	int T;
	scanf("%d",&T);
	while (T--) {
		solve();
	}
	return 0;
}
/*
1
2 3
1 1
2 2
2 1 2
*/
