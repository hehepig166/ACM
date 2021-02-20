//https://leetcode-cn.com/problems/smallest-string-with-swaps/
#include <vector>
#include <string>
#include <iostream>
#include <algorithm>
using namespace std;

class Solution {

private:
    vector<int> f,vis;
    vector<vector<int>> head;

public:

    int Fa(int x) {
        return f[x]==x ? x : f[x]=Fa(f[x]);
    }

    void dfs(int x, vector<int> &vis) {
        vis[x]=1;
        for (int i=0; i<head[x].size(); ++i) if (!vis[head[x][i]]) {
            f[head[x][i]]=Fa(x);
            dfs(head[x][i],vis);
        }
    }

    string smallestStringWithSwaps(string s, vector<vector<int>>& pairs) {
        string ret=s;
        int n=s.length();

        head.clear();
        head.resize(n);

        for (int i=0; i<pairs.size(); ++i) {
            head[pairs[i][0]].push_back(pairs[i][1]);
            head[pairs[i][1]].push_back(pairs[i][0]);
        }

        f.clear();
        f.resize(n);

        vis.clear();
        vis.resize(n);
        
        for (int i=0; i<n; ++i) {
            f[i]=i;
        }

        for (int i=0; i<n; ++i) {
            if (!vis[i])
                dfs(i,vis);
        }

        vis.clear();
        vis.resize(n);

        vector<char>tmp;

        vector<vector<int>> A(n);
        
        for (int i=0; i<n; ++i) {
        	A[f[i]].push_back(i);
		}
		
		for (int i=0; i<n; i++) if (A[i].size()>0) {
			tmp.clear();
			for (int j=0; j<A[i].size(); ++j) {
				tmp.push_back(s[A[i][j]]);
			}
			sort(tmp.begin(),tmp.end());
			for (int j=0; j<A[i].size(); ++j) {
				ret[A[i][j]]=tmp[j];
			}
		}

        return ret;
    }
};

int main()
{
	string s="dcab";
	vector<vector<int>> pairs={{0,3},{1,2},{0,2}};
	Solution S;
	cout <<S.smallestStringWithSwaps(s,pairs) <<endl;
	return 0;
}
