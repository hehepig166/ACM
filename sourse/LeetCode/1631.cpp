//https://leetcode-cn.com/problems/path-with-minimum-effort/
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    struct EDGE {
        int u,v,w;
        EDGE(int uu=0, int vv=0, int ww=0) :u(uu),v(vv),w(ww){}
    };
    static bool cmp(EDGE x, EDGE y) {
        return x.w<y.w;
    }

    int ID(int x,int y) {
        return x*101+y;
    }

	int f[20000];
	int Fa(int x) {
		return f[x]==x ? x : f[x]=Fa(f[x]);
	}

    int minimumEffortPath(vector<vector<int>>& heights) {
    	int ans;
        int n=heights.size(),m=heights[0].size();

        vector<EDGE> E;

        for (int i=0; i<n; i++) {
        	for (int j=0; j<m; j++) {
        		if (i>0)
        			E.emplace_back(EDGE(ID(i,j),ID(i-1,j),abs(heights[i][j]-heights[i-1][j])));
        		if (j>0)
        			E.emplace_back(EDGE(ID(i,j),ID(i,j-1),abs(heights[i][j]-heights[i][j-1])));
        		if (i<n-1)
        			E.emplace_back(EDGE(ID(i,j),ID(i+1,j),abs(heights[i][j]-heights[i+1][j])));
        		if (j<m-1)
        			E.emplace_back(EDGE(ID(i,j),ID(i,j+1),abs(heights[i][j]-heights[i][j+1])));
			}
		}

        sort(E.begin(),E.end(),cmp);
        
        for (int i=ID(0,0),mi=ID(n,m); i<=mi; i++) {
        	f[i]=i;
		}
		
		for (auto e: E) {
			int fu=Fa(e.u);
			int fv=Fa(e.v);
			f[fu]=fv;
			if (Fa(ID(0,0))==Fa(ID(n-1,m-1))) {
				return e.w;
			}
		}
        
        return -1;
    }
};

int main()
{
	Solution S;
	vector<vector<int>> A={{1,10,6,7,9,10,4,9}};
	cout <<S.minimumEffortPath(A);
	
	return 0;
}
