//https://leetcode-cn.com/problems/two-sum/
#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n=nums.size();
        for (int i=0; i<n; ++i) {
            for (int j=i+1; j<n; ++j) {
                if (nums[i]+nums[j]==target) {
                    return vector<int>{i,j};
                }
            }
        }
        return vector<int>{};
    }
};

int main()
{
	vector<int> nums={3,2,3},ans;
	Solution S;
	ans=S.twoSum(nums,6);
	cout <<ans[0] <<endl <<ans[1] <<endl;
	return 0;
}
