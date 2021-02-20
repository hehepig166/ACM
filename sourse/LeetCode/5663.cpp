//https://leetcode-cn.com/contest/weekly-contest-225/problems/find-kth-largest-xor-coordinate-value/
#include <bits/stdc++.h>
using namespace std;

int a[1005][1005]={0};

class Solution {
public:

    int n,m,t1,t2,t3;
    int kthLargestValue(vector<vector<int>>& matrix, int k) {
        vector<int> ret;
        m=matrix.size();
        n=matrix[0].size();
        for (int i=0; i<m; i++) {
            for (int j=0; j<n; j++) {
                t1=(i>0) ? a[i-1][j] : 0;
                t2=(j>0) ? a[i][j-1] : 0;
                t3=(i>0 && j>0) ? a[i-1][j-1] : 0;
                a[i][j]=t1^t2^t3^matrix[i][j];
                ret.emplace_back(a[i][j]);
            }
        }
        sort(ret.begin(),ret.end());
        return ret[n*m-k];
    }
};

int main()
{
	int aa=1;
	vector<vector<int>> A={{5,2},{1,6}};
	Solution S;
	cout <<S.kthLargestValue(A,4) <<endl;
	return 0;
}
