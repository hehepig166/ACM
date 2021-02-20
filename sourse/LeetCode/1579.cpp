//https://leetcode-cn.com/problems/remove-max-number-of-edges-to-keep-graph-fully-traversable/
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    int Fa(int x, vector<int> &f) {
        return f[x]==x ? x : f[x]=Fa(f[x],f);
    }

    int maxNumEdgesToRemove(int n, vector<vector<int>>& edges) {
        int ans=0;

        vector<int> f[4];
        for (int i=0; i<=n; i++) {
            f[3].emplace_back(i);
        }
        
        vector<vector<int>> E[4];
        for (auto I: edges) {
            E[I[0]].emplace_back(I);
        }
        
        int cnt[4],fu,fv;

        cnt[3]=n;
        for (auto I: E[3]) {
            fu=Fa(I[1],f[3]);
            fv=Fa(I[2],f[3]);
            if (fu!=fv) {
                f[3][fu]=fv;
                cnt[3]--;
            }
            else {
                ans++;
            }
        }

        cnt[1]=cnt[2]=cnt[3];
        f[1]=f[2]=f[3];
        for (int i=1; i<=2; i++) {
            for (auto I: E[i]) {
                fu=Fa(I[1],f[i]);
                fv=Fa(I[2],f[i]);
                if (fu!=fv) {
                    f[i][fu]=fv;
                    cnt[i]--;
                }
                else {
                    ans++;
                }
            }
        }

        if (cnt[1]!=1 || cnt[2]!=1) {
            ans=-1;
        }

        return ans;

    }
};

int main()
{
	Solution S;
	vector<vector<int>> A={{3,2,3},{1,1,2},{2,3,4}};
	cout <<S.maxNumEdgesToRemove(4,A) <<endl;
	return 0;
}
