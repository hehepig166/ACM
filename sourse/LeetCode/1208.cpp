#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int equalSubstring(const string &s, const string &t, const int &maxCost) {
        int n=s.length(),l,r,ans,ls,rs;
        if (n==0)
            return 0;      

        ans=0;
        l=0,r=1;
        ls=0,rs=abs(s[0]-t[0]);

        for (; r<=n; rs+=abs(s[r]-t[r]),r++) {

            while (rs-ls>maxCost)
                ls+=abs(s[l]-t[l]),l++;
            
            ans=max(ans,r-l);
        }

        return ans;
    }
};

int main()
{
    Solution S;
    cout <<S.equalSubstring("abcd","bcdf",3) <<endl;
    return 0;
}