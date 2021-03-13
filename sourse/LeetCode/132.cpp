#include <bits/stdc++.h>
using namespace std;


class Solution {
public:
    int minCut(string s) {
        int n=s.length();
        vector<vector<bool>> f(n+1,vector<bool>(n+1));
        for (int len=1,r; len<=n; len++) {
            for (int l=n-len; l>=0; l--) if ((r=l+len-1)<n) {
                if (s[l]==s[r]) {
                    if (r-l<=1)
                        f[l][r]=1;
                    else
                        f[l][r]=f[l+1][r-1];
                }
                else {
                    f[l][r]=0;
                }
            }
        }

        vector<int> Min(n,n);
        Min[0]=1;
        for (int i=1; i<n; i++) {
        	if (f[0][i]) {
        		Min[i]=1;
        		continue;
			}
            for (int j=0; j<i; j++) if (f[j+1][i])
                Min[i]=min(Min[i],Min[j]+1);
        }
        
        return Min[n-1]-1;
    }
};


int main()
{
	Solution S;
	cout <<S.minCut("aab") <<endl;
	return 0;
}
