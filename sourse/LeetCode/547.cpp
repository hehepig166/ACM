//https://leetcode-cn.com/problems/number-of-provinces/
#include <vector>
#include <cstring>
#include <iostream>
using namespace std;

class Solution {
private:
    int head[201],nxt[80005],V[80005],num;
    int f[201],vis[201];
    int Ans;
public:

    Solution() {
        memset(head,0,sizeof(head));
        memset(vis,-1,sizeof(vis));
        nxt[0]=0;
        //memset(nxt,0,sizeof(nxt));
        num=0;
    }

    #define Add(x,y) (nxt[++num]=head[x],V[num]=y,head[x]=num)
    #define For(x) for(int h=head[x],o=V[h]; h; o=V[h=nxt[h]])

    int Fa(int x) {
        return f[x]==x ? x : f[x]=Fa(f[x]);
    }

    void dfs(int x) {
        vis[x]=1;
        For(x) if (vis[o]==-1) {
        	Ans--;
            f[o]=Fa(x);
            dfs(o);
        }
    }

    int findCircleNum(vector<vector<int>>& isConnected) {
        int N=isConnected.size();
        Ans=N;

        //½¨Í¼
        for (int i=0; i<N; i++) {
            f[i]=i;
            for (int j=i+1; j<N; j++)
                if (isConnected[i][j]) {
                    Add(i,j);
                    Add(j,i);
                }
        }

        for(int i=0; i<N; i++)
            if (vis[i]==-1) {
                dfs(i);
            }

/*
        memset(vis,-1,sizeof(vis));
        for (int i=0; i<N; i++) {
            if (vis[f[i]]==-1) {
                Ans++;
                vis[f[i]]=1;
            }
        }
*/
        return Ans;
    }

    #undef Add
    #undef For
};

int main()
{
	int N=4,tmp;
	vector<int> tmpv;
	vector<vector<int>> A;
	for (int i=1; i<=N; i++) {
		tmpv.clear();
		for (int j=1; j<=N; j++) {
			cin >>tmp;
			tmpv.push_back(tmp);
		}
		A.push_back(tmpv);
	}
	
	Solution S;
	cout << S.findCircleNum(A) <<endl;
	
	return 0;
}
/*
1 1 0
1 1 0
0 0 1

1 0 0 1
0 1 1 0
0 1 1 1
1 0 1 1
*/
