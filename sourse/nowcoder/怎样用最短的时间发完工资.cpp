#include <bits/stdc++.h>
using namespace std;

vector<int> g[105];
int t[105];

void dfs(int x)
{
	t[x]=0;
	vector<int> s;
	int num=0;
	for (int o: g[x]) {
		dfs(o);
		s.emplace_back(t[o]);
		num++;
	}
	sort(s.begin(),s.end());
	
	t[x]=num;
	
	for (int i=num-1,j=1; i>=0; i--,j++) {
		t[x]=max(t[x],s[i]+j);
	}
}

int main()
{
	int n;
	scanf("%d",&n);
	for (int i=0,tmp; i<n; i++) {
		scanf("%d",&tmp);
		if (i>0) {
			g[tmp].emplace_back(i);
		}
	}
	
	dfs(0);
	
	printf("%d\n",t[0]);
	return 0;
}
