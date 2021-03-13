#include <bits/stdc++.h>
using namespace std;


vector<int> b;
int id[20005],he[20005];
bool cmp(int x, int y) {
	return b[id[x]]<b[id[y]];
}

#define I id[i]

class Solution {
	vector<vector<int>> a;
	vector<int> G[20005];
public:
    vector<int> countPairs(int n, vector<vector<int>>& edges, vector<int>& queries) {       
    	a.clear();
        a.resize(n+1,vector<int>(n+1,0));
        b.clear();
        b.resize(n+1,0);
        for (int i=1; i<=n; i++)
            G[i].clear();
        
        for (auto &E: edges) {
            //直连边数
            a[E[0]][E[1]]++;
            a[E[1]][E[0]]++;

            //度
            b[E[0]]++;
            b[E[1]]++;

            //边
            G[E[0]].push_back(E[1]);
            G[E[1]].push_back(E[0]);
        }
        
        for (int i=1; i<=n; i++)
        	id[i]=i;
		sort(id+1, id+n+1, cmp);
		for (int i=1; i<=n; i++)
			he[id[i]]=i;

        vector<int> ret;
        int ans,pt,tmp;
        
        for (int q: queries) {
            ans=0;
            pt=n;
            for (int i=1; i<n; i++) {
            	for (; pt>i && b[id[pt]]+b[I]>q; pt--)
					continue;
            	
            	tmp=max(i,pt);
            	
            	ans+=(n-tmp);
            	
            	for (int j: G[I])
					if(he[j]>tmp && b[j]+b[I]-a[j][I]<=q)
						ans--;
			}
			ret.emplace_back(ans);
        }
        
        return ret;
        
    }
};

int main()
{
	vector<vector<int>> A={{5,2},{3,5},{4,5},{1,5},{1,4},{3,5},{2,6},{6,4},{5,6},{5,6},{4,6},{6,2},{2,6},{5,4},{6,1},{6,1},{2,5},{1,3},{3,1},{4,5}};
	vector<int> Q={9},aa;
	Solution S;
	aa=S.countPairs(6,A,Q);
	for (auto i: aa)
		cout <<i <<endl;
		
	puts("");
		
	vector<vector<int>> AA={{1,2},{2,4},{1,3},{2,3},{2,1}};
	vector<int> QQ={2,3};
	aa=S.countPairs(4,AA,QQ);
	for (auto i: aa)
		cout <<i <<endl;
	
	return 0;
}

/*
6
[[5,2],[3,5],[4,5],[1,5],[1,4],[3,5],[2,6],[6,4],[5,6],[4,6],[6,2],[2,6],[5,4],[6,1],[6,1],[2,5],[1,3],[1,3],[4,5]]
[6,9,2,1,2,3,6,6,6,5,9,7,0,4,5,9,1,18,8,9]

vector<vector<int>> A={{1,5},{1,5},{3,4},{2,5},{1,3},{5,1},{2,3},{2,5}};
	vector<int> Q={1,2,3,4,5},aa;
	
vector<vector<int>> A={{1,2},{2,4},{1,3},{2,3},{2,1}};
	vector<int> Q={2,3},aa;
*/
