//https://leetcode-cn.com/problems/longest-substring-without-repeating-characters/
#include <string>
#include <iostream>
using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int Ans=1;
        int cnt[128]={0};
        int n=s.length();

        cnt[s[0]]++;

        for (int L=0,R=1; R<n; R++) {
            if (++cnt[s[R]] > 1) {
                while (cnt[s[R]]>1) {
                    --cnt[s[L++]];
                }
            }
            Ans=max(Ans,R-L+1);
        }

        return Ans;
    }
};

int main()
{
	string a="bbbbb";
	Solution S;
	cout <<S.lengthOfLongestSubstring(a) <<endl;
	return 0;
}
