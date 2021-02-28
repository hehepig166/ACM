#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> transpose(vector<vector<int>>& matrix) {
        int n=matrix.size()-1;
        for (int s=n+n-1; s>0; s--)
            for (int i=max(0,s-n),j=s-i; i<j; i++,j--)
                swap(matrix[i][j],matrix[j][i]);
        return matrix;
    }
};

int main()
{
	vector<vector<int>> A={{1,2,3},{4,5,6},{7,8,9}},B;
	Solution S;
	B=S.transpose(A);
	return 0;
}
