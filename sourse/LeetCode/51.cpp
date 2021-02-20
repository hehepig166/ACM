//https://leetcode-cn.com/problems/n-queens/
#include <vector>
#include <string>
#include <iostream>
using namespace std;

class Solution {
public:
#define MAXN 10
    int N,cnt;
    int col[MAXN]={0},sla1[2*MAXN]={0},sla2[2*MAXN]={0};

    void dfs(int dep, int a[]) {
        if (dep==N) {
            cnt++;
            return;
        }
        for (int i=0; i<N; i++) {
            if (!col[i] && !sla1[i-dep+MAXN] && !sla2[dep+i]) {
                col[i]=1;
                sla1[i-dep+MAXN]=1;
                sla2[dep+i]=1;
                a[dep]=i;
                dfs(dep+1,a);
                col[i]=0;
                sla1[i-dep+MAXN]=0;
                sla2[dep+i]=0;
            }
        }
    }

    int totalNQueens(int n) {
        vector<vector<string>> ret;
        N=n;
        cnt=0;
        int a[MAXN]={0};
        dfs(0,a);
        return cnt;
    }
};

int main()
{
	Solution S;
	cout <<S.totalNQueens(4);
	
	return 0;
}
