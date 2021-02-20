//https://leetcode-cn.com/problems/min-cost-to-connect-all-points/
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

class Solution {
public:

    static inline int dis(int x,int y,vector<vector<int>>& points) {
        return abs(points[x][0]-points[y][0])+abs(points[x][1]-points[y][1]);
    }

    struct EDGE {
        int u,v,w;
        bool operator> (const EDGE &b) {
            return w>b.w;
        }
        bool operator< (const EDGE &b) {
        	return w<b.w;
		}
        EDGE(int uu, int vv, vector<vector<int>>& points) {
            u=uu;
            v=vv;
            w=dis(u,v,points);
        }
    };

    vector<EDGE> E;

    vector<int> f;
    int Fa(int x) {
        return f[x]==x ? x : f[x]=Fa(f[x]);
    }

    int minCostConnectPoints(vector<vector<int>>& points) {
        int Ans=0;
        int n=points.size(),m;
        f.resize(n);
        for (int i=0; i<n; i++) {
            for (int j=i+1; j<n; j++) {
                E.push_back(EDGE(i,j,points));
            }
            f[i]=i;
        }
        sort(E.begin(),E.end());
        m=E.size();

        for (int i=0,fu,fv; i<m; i++) {
            EDGE tmp=E[i];
            fu=Fa(tmp.u);
            fv=Fa(tmp.v);
            if (fu!=fv) {
                Ans+=tmp.w;
                f[fu]=fv;
            }
        }

        return Ans;
    }
};

int main()
{
	return 0;
}
