//https://leetcode-cn.com/problems/redundant-connection/
#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    vector<vector<int>> graph;
    vector<int> f;

    int Fa(int x) {
        return f[x]==x ? x : f[x]=Fa(f[x]);
    }

    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n=edges.size();

        f.clear();
        for (int i=0; i<=n; ++i) {
            f.push_back(i);
        }
		
		graph.clear();
		graph.resize(n+1);
        for (int i=0,u,v; i<n; ++i) {
            u=Fa(edges[i][0]);
            v=Fa(edges[i][1]);
            if (u==v) {
                return edges[i];
            }
            f[u]=v;
            graph[edges[i][0]].push_back(edges[i][1]);
            graph[edges[i][1]].push_back(edges[i][0]);
        }
        return vector<int> {};
    }
};

int main()
{
	vector<vector<int>> edges={{1,2},{2,3},{3,4},{1,4},{1,5}};
	vector<int> ans;
	Solution S;
	ans=S.findRedundantConnection(edges);
	cout <<ans[0] <<endl <<ans[1] <<endl;
	return 0;
}
