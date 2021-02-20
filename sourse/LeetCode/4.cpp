//https://leetcode-cn.com/problems/median-of-two-sorted-arrays/
#include <iostream>
#include <vector>
using namespace std;


class Solution {
public:
	
	int findK(vector<int>& nums1, vector<int>& nums2, int k) {
		int n1=nums1.size(),n2=nums2.size();
		int p1=0,p2=0;
		int t1,t2;
		
		while (1) {
			
			if (p1==n1) {
				return nums2[p2+k-1];
			}
			else if (p2==n2) {
				return nums1[p1+k-1];
			}
			else if (k==1) {
				return min(nums1[p1],nums2[p2]);
			}
			
			t1=min(p1+k/2,n1);
			t2=min(p2+k/2,n2);
			
			if (nums1[t1-1]>nums2[t2-1]) {
				k-=t2-p2;
				p2=t2;
			}
			else {
				k-=t1-p1;
				p1=t1;
			}
			
		}
		
		return -1;
	}
	
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
		
		int n1=nums1.size(),n2=nums2.size();
		if ((n1+n2)%2)
			return (findK(nums1,nums2,(n1+n2)/2+1));
		else
			return (findK(nums1,nums2,(n1+n2)/2)+findK(nums1,nums2,(n1+n2)/2+1))/2.0;
		
    }
};


int main()
{
	Solution S;
	vector<int> A={1,2};
	vector<int> B={3,4};
	cout <<S.findMedianSortedArrays(A,B);
	return 0;
}
