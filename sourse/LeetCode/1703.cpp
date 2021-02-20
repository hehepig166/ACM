//https://leetcode-cn.com/problems/minimum-adjacent-swaps-for-k-consecutive-ones/
#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    int minMoves(vector<int>& nums, int k) {
    	int Ans=2147483647,tmp;
		vector<int> index;
		for (int i=0; i<nums.size(); ++i) {
			if (nums[i]==1) {
				index.push_back(i-index.size());
			}
		}
		
		vector<int> sum(index.size()+1,0);
		for (int i=0; i<index.size(); ++i) {
			sum[i+1]=sum[i]+index[i];
		}
		
		for (int L=0,R=L+k-1,M; R<index.size(); ++L,++R) {
			M=(L+R)>>1;
			tmp=index[M]*(M-L)-(sum[M]-sum[L]);
			tmp+=(sum[R+1]-sum[M+1])-index[M]*(R-M);
			Ans=min(Ans,tmp);
		}
		return Ans;
    }
};

int main()
{
	vector<int> nums={0,1,0,0,1,1,0,1,0,1,1,1,1,0,1,0};
	Solution S;
	cout <<S.minMoves(nums,7) <<endl;
	return 0;
}
