//https://leetcode-cn.com/problems/rotate-array/
#include <cstdio>
#include <vector>
using namespace std;

class Solution {
public:

    void solu1(vector<int>& nums, int k) {
        int len=nums.size(),i;
        if (len<=1)
            return;
        else
            k%=len;

        while (k--) {
            for (i=len-1; i; i--)
                swap(nums[i],nums[i-1]);
        }
    }

    void solu2(vector<int>& nums, int k) {
        int n=nums.size();
        vector<int> tmp(n);
        for (int i=0; i<n; ++i) {
            tmp[(i+k)%n]=nums[i];
        }
        nums.assign(tmp.begin(),tmp.end());
    }

    void solu3(vector<int>& nums, int k) {
        int n=nums.size(),cnt=0;
        int start,current,buffer;

        k%=n;

        for (start=0; cnt<n; start++) {
            current=start;
            buffer=nums[start];
            do {
                cnt++;
                current=(current+k)%n;
                swap(buffer,nums[current]);
            } while (current != start);
        }
    }
    
    void reverse(vector<int> &nums, int L, int R) {
        while (L<R) {
            swap(nums[L],nums[R]);
            --R;
            ++L;
        }
    }
    void solu4(vector<int>& nums, int k) {
        k%=nums.size();
        reverse(nums,0,nums.size()-1);
        reverse(nums,0,k-1);
        reverse(nums,k,nums.size()-1);
    }

    void rotate(vector<int>& nums, int k) {
        solu4(nums,k);
    }
};

int main()
{
	vector<int> a={1,2,3,4},b;
	Solution S;
	S.rotate(a,2);
	for (int i=0; i<4; i++)
		printf("%d ",a[i]);
	return 0;
} 
