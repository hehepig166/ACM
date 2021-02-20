//
#include <string>
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    string longestPalindrome(string s) {
        char ch[3000];
        int n=0,sl=s.length();
        int Maxlen=0,l=0,r=0;
        
        ch[n++]=0;
        for (int i=0; i<sl; i++) {
        	ch[n++]=s[i];
        	ch[n++]=0;
		}
		ch[n]=-1;
		
		vector<vector<bool>> f(n);
        for (int i=0; i<n; i++)
        	f[i].resize(n);
			
		
		for (int i=0; i<n; i++) {
			f[i][i]=1;
			f[i][i+1]=ch[i]==ch[i+1];
		}
		
		for (int k=2,mark; k<n; k++) {
			mark=-1;
			for (int i=0; i+k<n; i++) {
				if (f[i+1][i+k-1] && ch[i]==ch[i+k]) {
					f[i][i+k]=1;
					mark=i;
				}
			}
			if (mark>=0) {
				Maxlen=k;
				l=mark;
				r=mark+k;
			}
		}
		
		string ret="";		
		for (int i=l; i<=r; i++) {
			if (ch[i]!=0) {
				ret+=ch[i];
			}
		}
		
		return ret;
    }
};

int main()
{
	Solution S;
	//cout <<S.longestPalindrome("xxxabbbxxxx") <<endl;
	cout <<S.longestPalindrome("") <<endl;
}
