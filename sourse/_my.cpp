#include <bits/stdc++.h>
using namespace std;

int n,m,a[100005],b[100005],c[100005],ans[100005];
vector<int> s[100005];

void solve() {
	scanf("%d%d",&n,&m);
	for (int i=1; i<=n; i++) {
		scanf("%d",&a[i]);
		s[i].clear();
	}
	for (int i=1; i<=n; i++) {
		scanf("%d",&b[i]);
	}
	for (int i=1; i<=m; i++) {
		scanf("%d",&c[i]);
	}
	
	for (int i=1; i<=n; i++) {
		if (b[i]!=a[i]) {
			s[b[i]].push_back(i);
		}
	}
	
	//get the trick point
	int ok=0;
	if (s[c[m]].empty()) {
		for (int i=1; i<=m; i++) {
			if (b[i]==c[m]) {
				ok=i;
				break;
			}
		}
	}
	else {
		ok=s[c[m]].back();
		s[c[m]].pop_back();
	}
	
	if (!ok) {
		puts("NO");
		return;
	}
	
	//get_ans
	ans[m]=ok;
	for (int i=1; i<m; i++) {
		if (s[c[i]].empty()) {
			ans[i]=ok;
		}
		else {
			ans[i]=s[c[i]].back();
			s[c[i]].pop_back();
		}
	}
	
	//check
	for (int i=1; i<n; i++) {
		if (!s[i].empty()) {
			puts("NO");
			return;
		}
	}
	puts("YES");
	for (int i=1; i<=m; i++) {
		printf("%d%c",ans[i],i==m ? '\n' : ' ');
	}
}

int main() {
	int T;
	scanf("%d",&T);
	while (T--) {
		solve();
	}
	return 0;
}
