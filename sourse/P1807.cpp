#include <cstdio>
#include <vector>
#include <queue>
using namespace std;

class Dij {
public: 
	struct cmp { 
		bool operator() (pair<int,long long> &a, pair<int,long long> &b) {
			return a.second>b.second;
		}
	};

	void Solve(int n, vector<pair<int,int>> *G, vector<long long> &D) {
		int u,v;
		long long w;
		vector<bool> done(n);
		priority_queue<pair<int,long long>,vector<pair<int,long long>>,cmp> q;
		D.resize(n,1000000);
		
		D[0]=0;
		q.push({0,0});
		while (!q.empty()) {
			int u=q.top().first;
			q.pop();
			if (done[u])
				continue;
			done[u]=1;
			
			for(auto X: G[u]) {
				v=X.first,w=X.second;
				if (D[v]>D[u]+w) {
					D[v]=D[u]+w;
					if (!done[v]) {
						q.push({v,D[v]});
					}
				}
			}
		}
	}

};

int main()
{
	int n,m;
	scanf("%d%d",&n,&m);
	
	vector<pair<int,int>> graph[1505];
	vector<long long> dis;
	
	for (int i=1,u,v,w; i<=m; i++) {
		scanf("%d%d%d",&u,&v,&w);
		u--,v--;
		graph[u].push_back({v,-w});
		//graph[v].push_back({u,w});
	}
	
	Dij Solution;
	
	Solution.Solve(n,graph,dis);
	
	printf("%lld\n",dis[n-1]==1000000 ? -1 : -dis[n-1]);
	return 0;
}

/*
4 8
1 3 6
1 3 7
1 2 1
1 4 3
3 2 9
4 3 7
1 3 10
2 4 3

3 3
1 3 153
1 3 11
1 2 123

*/
