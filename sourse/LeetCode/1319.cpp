//https://leetcode-cn.com/problems/number-of-operations-to-make-network-connected/submissions/
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

	int cnt;	//并查集个数 
    vector<int> f;
    int Fa(int x) {
        return f[x]==x ? x : f[x]=Fa(f[x]);
    }

    int makeConnected(int n, vector<vector<int>>& connections) {
        int m=connections.size();

        //无法连通
        if (m<n-1) {
            return -1;
        }
	
		cnt=n;
        f.resize(n);
        for (int i=0; i<n; i++) {
            f[i]=i;
        }

        for (auto E: connections) {
            int fu=Fa(E[0]);
            int fv=Fa(E[1]);
            if (fu!=fv) {
                f[fu]=fv;
                cnt--;
            }
        }
		
        return cnt-1;
    }
};

int main()
{
	vector<vector<int>> A={{0,2},{2,7},{5,7},{2,6},{1,3},{4,6},{1,2}};
	Solution S;
	cout <<S.makeConnected(8,A) <<endl;
	return 0;
}
