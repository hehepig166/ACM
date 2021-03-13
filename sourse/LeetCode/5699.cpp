#include <bits/stdc++.h>
using namespace std;


class Solution {
    vector<long long> dis;
    vector<long long> f;
    vector<int> din;
    vector<int> dout;
    vector<vector<int>> G;
public:
    
    void dfs(int x, vector<vector<int>>& edges) {
    	for (auto i: G[x]) {
    		int v=(edges[i][0]==u ? edges[i][1] : edges[i][0]);
    		
    		if (dis[v]>=dis[x])
    			continue;
    		
    		dout[x]++;
    		din[v]++;
    		
    		if (din[v]==1)
    			dfs(v);
		}
	}
    
    void bfs(int n, vector<vector<int>>& edges) {
    	vector<int> vis[]
    	priority_queue<pair<int, int>> q;	//´ó¸ù¶Ñ 
    	q.push(make_pair(0,1));
    	while (q.size()) {
    		int u=q.top().second(),cnt=q.top().first;
    		q.pop();
    		for (auto i: G[u]) {
    			int v=(edges[i][0]==u ? edges[i][1] : edges[i][0]);
    			
			}
		}
	}
    
    int countRestrictedPaths(int n, vector<vector<int>>& edges) {
        dis.clear();
        dis.resize(n+1);
        
        G.clear();
        G.resize(n+1);
        for (int i=0,nn=edges.size(); i<nn; i++) {
            G[edges[i][0]].emplace_back(i);
            G[edges[i][1]].emplace_back(i);
        }
        
        for (int i=0; i<=n; i++)
            dis[i]=1e10;
        vector<int> vis(n+1);
        
        priority_queue<pair<long long, int>> q;
        
        dis[n]=0;
        q.push(make_pair(0,n));
        while (q.size()) {
            int u=q.top().second;
            q.pop();
            
            if (vis[u])
                continue;
            
            vis[u]=1;
            for (auto i: G[u]) {
                int v=(edges[i][0]==u ? edges[i][1] : edges[i][0]);
                int w=edges[i][2];
                if (dis[v]>dis[u]+w) {
                    dis[v]=dis[u]+w;
                    q.push(make_pair(-dis[v],v));
                }
            }
        }
        
        for (int i=1; i<=n; i++)
        	printf("[%d]\t%lld\n",i,dis[i]);
        
        din.clear();
        din.resize(n+1);
        dout.clear();
        dout.resize(n+1);
        
        dfs(1);
    }
};

int main()
{
	Solution S;
	vector<vector<int>> A={{1,3,1},{4,1,2},{7,3,4},{2,5,3},{5,6,1},{6,7,2},{7,5,3},{2,6,4}};
	//vector<vector<int>> A={{1,2,3},{1,3,3},{2,3,1},{1,4,2},{5,2,2},{3,5,1},{5,4,10}};
	S.countRestrictedPaths(7,A);
	
}
