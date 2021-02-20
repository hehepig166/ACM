//https://leetcode-cn.com/problems/swim-in-rising-water/
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
	#define N 5
    #define ID(i,j) ((i)*N+(j))
    int f[ID(N,N)],id[ID(N,N)];
    int Fa(int x){return f[x]==x ? x : f[x]=Fa(f[x]);}
    int n;
    int swimInWater(vector<vector<int>>& grid) {
        n=grid.size();

        for (int i=0; i<n; i++) {
            for (int j=0; j<n; j++) {
                id[grid[i][j]]=ID(i,j);
                f[ID(i,j)]=ID(i,j);
            }
        }

        for (int t=0,mt=n*n; t<mt; t++) {
            int x=id[t]/N,y=id[t]%N;
            if (x>0 && grid[x-1][y]<=t) {
                f[Fa(f[id[t]])]=Fa(ID(x-1,y));
            }
            if (y>0 && grid[x][y-1]<=t) {
                f[Fa(f[id[t]])]=Fa(ID(x,y-1));
            }
            if (x<n-1 && grid[x+1][y]<=t) {
                f[Fa(f[id[t]])]=Fa(ID(x+1,y));
            }
            if (y<n-1 && grid[x][y+1]<=t) {
                f[Fa(f[id[t]])]=Fa(ID(x,y+1));
            }
            if (Fa(0)==Fa(ID(n-1,n-1))) {
                return t;
            }
        }
        return n*n-1;
    }
};

int main()
{
	Solution S;
	vector<vector<int>> A={{7,23,21,9,5},{3,20,8,18,15},{14,13,1,0,22},{2,10,24,17,12},{6,16,19,4,11}};
	cout <<S.swimInWater(A) <<endl;
	return 0;
}
