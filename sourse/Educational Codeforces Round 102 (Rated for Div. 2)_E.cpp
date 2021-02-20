#include <queue>
#include <vector>
#include <cstring>
#include <cstdio>
using namespace std;
#define ID(x,y,z) (((x)<<3)+((y)<<1)+z)
const int N=200015;
 
vector<pair<int,int>> graph[N];
long long d[N][2][2];
bool vis[N][2][2];
 
int n,m;
 
struct cmp {
	bool operator() (pair<long long,long long> x, pair<long long,long long> y) {
		return x.first > y.first;
	}
};
 
 
int main()
{
	scanf("%d%d",&n,&m);
	for (int i=1,u,v,w; i<=m; i++) {
		scanf("%d%d%d",&u,&v,&w);
		u--;
		v--;
		graph[u].emplace_back(make_pair(v,w));
		graph[v].emplace_back(make_pair(u,w));
	}
	
	for (int i=0; i<n; i++) {
		for (int j=0; j<2; j++) {
			for (int k=0; k<2; k++) {
				d[i][j][k]=10000000000000000ll;
				vis[i][j][k]=0;
			}
		}
	}
	d[0][0][0]=0;
		
	priority_queue<pair<long long,long long>,vector<pair<long long,long long>>,cmp> q;
	q.push({0,ID(0,0,0)});
	
	while (!q.empty()) {
		int u,mx,mn;
		u=(q.top().second>>3);
		mx=(q.top().second>>1)&1;
		mn=q.top().second&1;
		q.pop();
		
		if (vis[u][mx][mn])
			continue;
		vis[u][mx][mn]=1;
		
		for (pair<int,int> I: graph[u]) {
			int v=I.first,w=I.second;
			for (int i=0; i<=(mx^1); i++) {
				for (int j=0; j<=(mn^1); j++) {
					if (d[v][mx|i][mn|j]>d[u][mx][mn]+1ll*(1-i+j)*w) {
						d[v][mx|i][mn|j]=d[u][mx][mn]+1ll*(1-i+j)*w;
						q.push(make_pair(d[v][mx|i][mn|j],ID(v,(mx|i),(mn|j))));
					}
				}
			}
		}
	}
	
	for (int i=1; i<n; i++) {
		printf("%lld ",d[i][1][1]);
	}
	puts("");
	
	
	return 0;
}
