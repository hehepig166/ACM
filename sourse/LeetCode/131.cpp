#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int n;
    vector<vector<bool>> f;
    vector<vector<string>> ret;

    void solve(int L, int R, string &s, vector<string> &ans) {

        if (L>=R) {
            ret.emplace_back(ans);
            return;
        }

        string tmp;
        for (int i=L; i<R; i++) {
            tmp+=s[i];
            if (f[L][i]) {
                ans.emplace_back(tmp);
                solve(i+1,R,s,ans);
                ans.pop_back();
            }
        }
    }

    vector<vector<string>> partition(string s) {
        n=s.length();
        f=vector<vector<bool>>(n,vector<bool>(n));
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

        ret.clear();
        vector<string> aaa;
        solve(0,n,s,aaa);
        return ret;
    }
};

int main()
{
	Solution S;
	vector<vector<string>> aaaa;
	aaaa=S.partition("a");
	for (auto A: aaaa) {
		cout <<endl;
		for (auto B: A)
			cout <<B <<" ";
	}
	return 0;
}

