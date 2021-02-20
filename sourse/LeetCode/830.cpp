//https://leetcode-cn.com/problems/positions-of-large-groups/
#include <vector>
#include <string>
#include <iostream>
using namespace std;

class Solution {
public:
    vector<vector<int>> largeGroupPositions(string s) {
        vector<vector<int>> ret;
        int len=s.length();
        int L=0;
        int R;
        for (R=0; R<len; R++) {
            if (s[R]!=s[L]) {
                if (R-L>=3)
                    ret.push_back((vector<int>){L,R-1});
                L=R;
            }
        }
        if (L<len) {
            if (len-L>=3)
                ret.push_back((vector<int>){L,len-1});
        }
        return ret;
    }
};

int main()
{
	string s="abcdddeeeeaabbbcd";
	Solution S;
	vector<vector<int>> ans=S.largeGroupPositions(s);
	vector<vector<int>>::iterator it=ans.begin();
	for (; it!=ans.end(); it++) {
		cout <<(*it)[0] <<" " <<(*it)[1] <<endl;
	}
	
	return 0;
}
