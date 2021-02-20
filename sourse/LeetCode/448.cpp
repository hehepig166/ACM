#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        int n=nums.size();
        vector<int> ret;
        for (int i=0; i<n; i++)
        	nums[i]--;
        for (int i=0; i<n; i++)
            if (nums[nums[i]%n]<n)
                nums[nums[i]%n]+=n;
        
        for (int i=0; i<n; i++)
            if (nums[i]<n)
                ret.push_back(i+1);
        
        return ret;
    }
};

int main()
{
	vector<int> A={4,3,2,7,8,2,3,1},ans;
	Solution S;
	ans=S.findDisappearedNumbers(A);
	
	return 0;
}
