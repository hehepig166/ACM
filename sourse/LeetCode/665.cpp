#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool checkPossibility(vector<int>& nums) {
        int n;
        n=nums.size();
        int cnt=-1;
        for (int i=1; i<n; i++) {
            if (nums[i]<nums[i-1]) {
                if (cnt!=-1) {
                    return false;
                }
                else {
                    cnt=i;
                }
            }
        }

        if (cnt==-1) {
            return true;
        }

        bool ret;
        ret=1;
        int tmp=nums[cnt];
        nums[cnt]=nums[cnt-1];
        for (int i=1; i<n; i++) {
            if (nums[i]<nums[i-1]) {
            	ret=0;
                break;
            }
        }
        if (ret) {
        	return true;
		}
		
		ret=1;
		nums[cnt]=tmp;
		nums[cnt-1]=nums[cnt];
		for (int i=1; i<n; i++) {
            if (nums[i]<nums[i-1]) {
            	ret=0;
                break;
            }
        }
        if (ret) {
        	return true;
		}


		return false;
    }
};

int main()
{
	vector<int> A={3,4,2,3};
	Solution S;
	cout <<S.checkPossibility(A) <<endl;
}
