#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> matrixReshape(vector<vector<int>>& nums, int r, int c) {
        vector<vector<int>> ret;
        int n,m;
        n=nums.size();
        if (n==0)
            return nums;
        m=nums[0].size();
        if (n*m==r*c) {
        	ret.resize(r);
            int I=0,J=0;
            for (int i=0; i<n; i++)
                for (int j=0; j<m; j++) {
                    ret[I].push_back(nums[i][j]);
                    I+=++J/c;
                    J%=c;
                }
            return ret;
        }
        return nums;
    }
};

int main()
{
	Solution S;
	vector<vector<int>> A ={{1,2},{3,4}};
	S.matrixReshape(A,1,4);
	return 0;
}
