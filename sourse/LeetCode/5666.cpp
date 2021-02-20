#include <bits/stdc++.h>
using namespace std;


int f[2005][2005],n,l,r,len,tmp;

class Solution {
public:
    bool checkPartitioning(string s) {
    	n=s.size();
    	memset(f,0,sizeof(f));
    	for (len=0; len<n; len++) {
    		for (l=n-len-1; l>=0; l--) {
    			r=l+len;
    			if (r-l<=1) {
    				f[l][r]=(s[l]==s[r]);
				}
				else {
					f[l][r]=(s[l]==s[r] && f[l+1][r-1]);
				}
			}
    	}
    	for (l=n-2; l>0; l--) {
    		for (r=n-2; r>=l; r--) {
    			if (f[0][l-1] && f[l][r] && f[r+1][n-1]) {
    				return 1;
				}
			}
		}
		return 0;
    }
};

int main()
{
	Solution S;
	cout <<S.checkPartitioning("bcbddxy") <<endl;
	return 0;
}
