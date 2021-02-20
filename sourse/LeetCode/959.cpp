//https://leetcode-cn.com/problems/regions-cut-by-slashes/
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int n,ans;
    vector<int> f;

    inline int ID(int x,int y) {return (x)*n+y;}
    inline int U(int x,int y) {return (ID(x,y)*4);}
    inline int R(int x,int y) {return (ID(x,y)*4+1);}
    inline int D(int x,int y) {return (ID(x,y)*4+2);}
    inline int L(int x,int y) {return (ID(x,y)*4+3);}

    int Fa(int x) {
        return f[x]==x ? x : f[x]=Fa(f[x]);
    }
    
    inline void con(int id1, int id2) {
        static int f1,f2;
        f1=Fa(id1);
        f2=Fa(id2);
        if (f1!=f2) {
            f[f1]=f2;
            ans--;
        }
    }

    int regionsBySlashes(vector<string>& grid) {
        n=grid.size();
        ans=n*n*4;
        f.resize(L(n,n),0);
        for (int i=L(n-1,n-1); i>=0; i--) {
            f[i]=i;
        }

        for (int i=0; i<n; i++) {
            int j=0,l=0;
            for (; j<n; j++) {
                if (grid[i][j]=='/') {
                    con(U(i,j),L(i,j));
                    con(D(i,j),R(i,j));
                    if (i>0) con(D(i-1,j),U(i,j));
                    if (i<n-1) con(U(i+1,j),D(i,j));
                    if (j>0) con(R(i,j-1),L(i,j));
                    if (j<n-1) con(L(i,j+1),R(i,j));
                }
                else if (grid[i][j]=='\\') {
                    con(U(i,j),R(i,j));
                    con(L(i,j),D(i,j));
                    if (i>0) con(D(i-1,j),U(i,j));
                    if (i<n-1) con(U(i+1,j),D(i,j));
                    if (j>0) con(R(i,j-1),L(i,j));
                    if (j<n-1) con(L(i,j+1),R(i,j));
                }
                else {
                    con(U(i,j),R(i,j));
                    con(L(i,j),D(i,j));
                    con(U(i,j),L(i,j));
                    con(D(i,j),R(i,j));
                    if (i>0) con(D(i-1,j),U(i,j));
                    if (i<n-1) con(U(i+1,j),D(i,j));
                    if (j>0) con(R(i,j-1),L(i,j));
                    if (j<n-1) con(L(i,j+1),R(i,j));
                }
            }
        }

        return ans;
    }
};

int main()
{
	Solution S;
	vector<string> A={"//","/ "};
	cout <<S.regionsBySlashes(A) <<endl;
	return 0;
}
