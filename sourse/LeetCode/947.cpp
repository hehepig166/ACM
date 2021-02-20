//https://leetcode-cn.com/problems/most-stones-removed-with-same-row-or-column/
#include <vector>
#include <algorithm>
#include <cstdio>
using namespace std;


class Solution {
public:
#define MAX 10000	
	int f[2*MAX+10],vis[2*MAX+10]={0};
	
	int Fa(int x) {
		return f[x]==x ? x : f[x]=Fa(f[x]);
	}
	
    int removeStones(vector<vector<int>>& stones) {
    	int ans=0;
    	
		for (int i=2*MAX+1; i>=0; i--) {
			f[i]=i;
		}
		
		for (auto I: stones) {
			f[Fa(I[0])]=Fa(I[1]+MAX+1);
		}
		
		for (auto I: stones) {
			ans+=vis[Fa(I[0])];
			vis[Fa(I[0])]=1;
		}
		
		return ans;
    }
};

int main()
{
	vector<vector<int>> stones={{3,2},{0,0},{3,3},{2,1},{2,3},{2,2},{0,2}};
	Solution S;
	printf("%d\n",S.removeStones(stones)); 
	return 0;
}
