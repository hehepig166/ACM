#include <bits/stdc++.h>
using namespace std;

class Solution {
    vector<vector<int>> a;
    
    inline int cnt(int l, int r, int k) {
        return a[r][k]-a[l-1][k];
    }
    
    inline int val(int l, int r) {
        int Min=1000,Max=-1;
        for (int i=0,tmp; i<26; i++) if ((tmp=cnt(l,r,i))){
            Min=min(Min,tmp);
            Max=max(Max,tmp);
        }
        return Max-Min;
    }
public:
    int beautySum(string s) {
        int n=s.length(),ans=0;
        if (n==0)
            return 0;
        
        a.resize(n+3);
        a[0]=vector<int>(26);
        for (int i=0; i<n; i++) {
            a[i+1]=a[i];
            a[i+1][s[i]-'a']++;
        }
        
        for (int i=0; i<n; i++)
            for (int j=i; j<n; j++)
                ans+=val(i+1,j+1);
        
        return ans;
    }
};

int main()
{
	Solution S;
	cout <<S.beautySum("aabcb") <<endl;
	return 0;
}
