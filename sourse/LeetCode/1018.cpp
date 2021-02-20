//https://leetcode-cn.com/problems/binary-prefix-divisible-by-5/
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<bool> prefixesDivBy5(vector<int>& A) {
        vector<bool> ret;
        int s=0;
        for (auto x: A) {
            s=((s<<1)+x)%10;
            ret.push_back(s%5==0);
        }
        return ret;
    }
};

int main()
{
	Solution S;
	vector<int> A={0,1,1,1,1,1};
	vector<bool> ans;
	ans=S.prefixesDivBy5(A);
	for (auto x: ans)
		cout <<x <<endl;
	return 0;
}
