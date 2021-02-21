#include <bits/stdc++.h>
using namespace std;

int f[1005][1005];

class Solution {
public:
    int longestPalindrome(string word1, string word2) {
        int n1=word1.size(),n2=word2.size(),ans=0;
        memset(f,0,sizeof(f));
        for (int i=n1-1; i>=0; i--)
            for (int j=0; j<n2; j++) {
                f[i][j]=f[i+1][j];
                if (j-1>=0)
                    f[i][j]=max(f[i][j],f[i][j-1]);
                if (word1[i]==word2[j])
                    f[i][j]=(j-1>=0) ? f[i+1][j-1]+2 : 2;
                
                ans=max(ans,f[i][j] + ((i!=n1-1 || j!=0) && f[i][j]>0) );
              	
            }
        return ans;
    }
};


int main()
{
	Solution S;
	cout <<S.longestPalindrome("rhuzwqohquamvsz","kvunbxje") <<endl;
	return 0;
}
/*
"rhuzwqohquamvsz","kvunbxje"
*/
