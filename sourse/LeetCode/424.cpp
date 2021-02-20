//https://leetcode-cn.com/problems/longest-repeating-character-replacement/
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int f[26];
    int characterReplacement(string s, int k) {
        int n=s.length();
        if (n<=0)
        	return 0;
        for (int i=0; i<26; i++)
            f[i]=0;
        
        int l=0,r=0,maxn=1,ans=1;
        f[s[0]-'A']++;
        
        while (1) {

            while (r-l+1-maxn<=k) {
                r++;
                if (r>=n) {
                	r=n-1;
                    break;
                }
                f[s[r]-'A']++;
                for (int i=0; i<26; i++)
                    maxn=max(maxn,f[i]);

            }

            while (r-l+1-maxn>k) {
            	f[s[l]-'A']--;
                l++;
                for (int i=0; i<26; i++)
                    maxn=max(maxn,f[i]);
            }

            ans=max(ans,r-l+1);
            
            if (r==n-1) {
            	break;
			}
        }

        return ans;
    }
};

int main()
{
	Solution S;
	cout <<S.characterReplacement("",2) <<endl;
	return 0;
}
