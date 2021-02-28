#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> flipAndInvertImage(vector<vector<int>>& A) {
        int n=A.size()-1;
        for (int i=0,tmp; i<=n; i++)
            for (int j=n/2,jj=n-j; j>=0; j--,jj++)
                A[i][j]^=(j==jj) ? 1 : (A[i][jj]^=((A[i][j]^=A[i][jj])^1));
        return A;
    }
};

int main()
{
	vector<vector<int>> A={{1,1,0},{1,0,1},{0,0,0}},B;
	Solution S;
	B=S.flipAndInvertImage(A);
	return 0;
}

/*
vector<vector<int>> A={{1,1,0,0},{1,0,0,1},{0,1,1,1},{1,0,1,0}},B;
*/
