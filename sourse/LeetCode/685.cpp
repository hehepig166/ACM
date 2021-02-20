//https://leetcode-cn.com/problems/redundant-connection-ii/description/

#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
	vector<int> par;
    vector<int> f;
    vector<int> tag;

    int Fa(int x) {
        return f[x]==x ? x : f[x]=Fa(f[x]);
    }

    vector<int> findRedundantDirectedConnection(vector<vector<int>>& edges) {
        int n=edges.size();
        f.clear();
        tag.clear();
        tag.resize(n);
        
        int st1=-1,st2=-1;
        
        for (int i=0; i<=n; ++i) {
            f.push_back(i);
            par.push_back(i);
        }
        for (int i=0,u,v; i<n; ++i) {
            u=edges[i][0];
            v=edges[i][1];

			if (par[v]!=v) {	//发生冲突 
				tag[i]=1;
				st1=i;
			}
			else {
				if (Fa(u)==Fa(v)) {	//形成环路 
					tag[i]=2;
					st2=i;
				}
				else {	//正常 
					par[v]=f[v]=u;
				}
			}
        }
        
        if (st1==-1) {
			return edges[st2];
		}
		else {
			if (st2==-1) {
				return edges[st1];
			}
			else {
				return vector<int> {par[edges[st1][1]],edges[st1][1]};
			}
		}
    }
};

int main()
{
	vector<vector<int>> edges={{1,2},{1,3},{2,3}};
	vector<int> ans;
	Solution S;
	ans=S.findRedundantDirectedConnection(edges);
	cout <<ans[0] <<endl <<ans[1] <<endl;
	return 0;
}

/*
{1,2},{3,1},{2,4},{5,1},{2,3},{6,5}
*/
