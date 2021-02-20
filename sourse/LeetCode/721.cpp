//https://leetcode-cn.com/problems/accounts-merge/
#include <vector>
#include <string>
#include <unordered_map>
#include <algorithm>
using namespace std;

class Djset {
public:
	vector<int> parent;
	vector<int> rank;
	Djset(int n):parent(vector<int>(n)),rank(vector<int>(n)) {
		for (int i=0; i<n; i++) {
			parent[i]=i;
		}
	}
	
	int find(int x) {
		return x==parent[x] ? parent[x] : parent[x]=find(parent[x]);
	}
	
	void merge(int x, int y) {
		int rootx=find(x);
		int rooty=find(y);
		if (rootx!=rooty) {
			if (rank[rootx]<rank[rooty]) {
				swap(rootx,rooty);
			}
			parent[rooty]=rootx;
			if (rank[rootx]==rank[rooty])
				rank[rootx]++;
		}
	}
};

class Solution {
public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
    	vector<vector<string>> res;
    	
		unordered_map<string,int> um;
		int n=accounts.size();
		
		Djset ds(n);
		
		for (int i=0; i<n; i++) {
			int m=accounts[i].size();
			for (int j=1; j<m; j++) {
				string s=accounts[i][j];
				if (um.find(s)==um.end()) {
					um[s]=i;
				}
				else {
					ds.merge(i,um[s]);
				}
			} 
		}
		
		unordered_map<int,vector<string>> umv;
		for (auto &[k,v]: um)
			umv[ds.find(v)].emplace_back(k);
		for (auto &[k,v]: umv) {
			sort(v.begin(),v.end());
			vector<string> tmp(1,accounts[k][0]);
			tmp.insert(tmp.end(),v.begin(),v.end());
			res.emplace_back(tmp);
		}
		
		return res;
    }
};

int main()
{
	
	return 0;
}
