#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int ans,n;
    vector<int> cnt[30];
    int K;
    string S;

#define CNT(ll, rr, tt) (cnt[tt][rr]-(ll ? cnt[tt][ll-1] : 0))

    void solve(int l, int r) {
        if (l>r) {
            return;
        }
        
        for (int t=0; t<26; t++) {
	        if (CNT(l,r,t)>0 && CNT(l,r,t)<K) {
	            int lst=l-(S[l]!=(t+'a'));
    	        for (int i=l; i<=r; i++) {
        	        if (S[i]==(t+'a')) {
        	            solve(lst+1,i-1);
        	            lst=i;
        	        }
        	    }
        	    if (lst<r)
					solve(lst+1,r);
				return;
    	    }
        }
        
        ans=max(ans,r-l+1);
        
    }


    int longestSubstring(string s, int k) {
        S=s;
        K=k;
        ans=0;
        n=s.length();
        for (int i=0; i<26; i++)
            cnt[i].resize(n,0);

        vector<int> tmp(26);
        for (int i=0; i<n; i++) {
            tmp[s[i]-'a']++;
            for (int j=0; j<26; j++)
                cnt[j][i]=tmp[j];
        }

        solve(0,n-1);

        return ans;
    }
};

int main()
{
	Solution S;
	cout <<S.longestSubstring("ababab",3) <<endl;
	
	return 0;
}
