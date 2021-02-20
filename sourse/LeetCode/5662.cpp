//https://leetcode-cn.com/contest/weekly-contest-225/problems/change-minimum-characters-to-satisfy-one-of-three-conditions/
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minCharacters(string a, string b) {
        int sa[30]={0},sb[30]={0},amin=2147483647,bmin=2147483647,amax=-1,bmax=-1;
        for (int i=0; i<a.length(); i++) {
            sa[a[i]-'a']++;
        }
        for (int i=0; i<b.length(); i++) {
            sb[b[i]-'a']++;
        }
        
        
        int ans=2147483647;
        
        //case1	a>=x>b
        for (int x=1; x<26; x++) {
        	int tmp=0;
        	for (int i=0; i<x; i++) {
        		tmp+=sa[i];
			}
			for (int i=x; i<26; i++) {
				tmp+=sb[i];
			}
			ans=min(ans,tmp);
		}
        
        //case2 b>=x>a
        for (int x=1; x<26; x++) {
        	int tmp=0;
        	for (int i=0; i<x; i++) {
        		tmp+=sb[i];
			}
			for (int i=x; i<26; i++) {
				tmp+=sa[i];
			}
			ans=min(ans,tmp);
		}
        
        //case3
        for (int x=0; x<26; x++) {
            int tmp=0;
            for (int i=0; i<26; i++) if (i!=x) {
                tmp+=sa[i]+sb[i];
            }
            ans=min(ans,tmp);
        }
        
        return ans;
    }
};

int main()
{
	Solution S;
	cout <<S.minCharacters("ace","abe");
	return 0;
}
