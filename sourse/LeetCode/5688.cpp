#include <bits/stdc++.h>
using namespace std;

int f[1005][1005][2][2];
int l[1005][30],r[1005][30];

class Solution {
public:
    int longestPalindrome(string word1, string word2) {
        string S=word1+word2;
        int n=S.length(),n1=word1.length(),n2=word2.length();
        
        memset(f,0,sizeof(f));
        
        vector<int> tmp1(30,-1);
        for (int i=0; i<26; i++) l[0][i]=-1;
        tmp1[S[0]-'a']=0;
        for (int i=1; i<n; i++) {
            for (int j=0; j<26; j++)
                l[i][j]=tmp1[j];
            tmp1[S[i]-'a']=i;
        }
        
        vector<int> tmp2(30,n);
        tmp2[S[0]-'a']=n;
        for (int i=0; i<26; i++) r[n-1][i]=n;
        for (int i=n-2; i>=0; i--) {
            for (int j=0; j<26; j++)
                r[i][j]=tmp2[j];
            tmp2[S[i]-'a']=i;
        }
        
        for (int i=0; i<n; i++)
        	f[i][i][1][1]=1;
        
        for (int len=2,i,j; len<=n; len++) {
            for (i=0,j=i+len-1; j<n; j++,i++) {
                if (j-1>=0) f[i][j][0][0]=max(f[i][j-1][0][1],f[i][j-1][0][0]);
                f[i][j][0][1]=f[i][j][1][0]=1;
                if (r[i][S[j]-'a']<j) f[i][j][0][1]=max(f[i][j][0][1],f[r[i][S[j]-'a']][j][0][0]+2);
                if (l[j][S[i]-'a']>i) f[i][j][1][0]=max(f[i][j][1][0],f[i][l[j][S[i]-'a']][0][0]+2);
                if (S[i]==S[j] && i+1<n && j-1>=0) {
					f[i][j][1][1]=max(f[i][j][1][1],f[i+1][j-1][0][0]+2);
					f[i][j][1][1]=max(f[i][j][1][1],f[i+1][j-1][0][1]+2);
					f[i][j][1][1]=max(f[i][j][1][1],f[i+1][j-1][1][0]+2);
					f[i][j][1][1]=max(f[i][j][1][1],f[i+1][j-1][1][1]+2);
				}
            }
        }
        
        int ans=0;
        for (int i=0; i<n1; i++)
        	for (int j=n-1; j>=n1; j--)
        			ans=max(ans,f[i][j][1][1]);
        return ans;
    }
};


int main()
{
	Solution S;
	cout <<S.longestPalindrome("uzqqsz","u") <<endl;
	return 0;
}
