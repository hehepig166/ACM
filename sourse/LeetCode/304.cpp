#include <bits/stdc++.h>
using namespace std;

class NumMatrix {
public:
#define I (i+1)
#define J (j+1)
    vector<vector<int>> A;
    NumMatrix(vector<vector<int>>& matrix) {
        int n=matrix.size();
        if (n==0)
            return;
        int m=matrix[0].size();
        
        A.resize(n+1);
        A[0].resize(m+1);
        for (int i=0; i<n; i++) {
        	A[I].resize(m+1);
        	for (int j=0; j<m; j++) {
        		A[I][J]=A[I-1][J]+A[I][J-1]-A[I-1][J-1]+matrix[i][j];
			}
        }
    }
    
    int sumRegion(int i1, int j1, int i2, int j2) {
        int ans;
        ans=A[i2+1][j2+1];
        ans-=A[i2+1][j1];
        ans-=A[i1][j2+1];
        ans+=A[i1][j1];
        return ans;
    }
#undef I
#undef J
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */

int main()
{
    vector<vector<int>> B={{3, 0, 1, 4, 2},{5, 6, 3, 2, 1},{1, 2, 0, 1, 5},{4, 1, 0, 1, 7},{1, 0, 3, 0, 5}};
    NumMatrix S(B);
    cout <<S.sumRegion(2,1,4,3) <<endl;
    return 0;
}
