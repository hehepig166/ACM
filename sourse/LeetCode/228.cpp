//https://leetcode-cn.com/problems/summary-ranges/
#include <string>
#include <conio.h>
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
	
	void Add(string &s,int n,int flag) {
		if (n>9 || n<-9)
			Add(s,n/10,flag);
		else if (flag) {
			s+='-';
		}
		s+=(char)(n%10+'0');
	}
	
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string> ret;
        string str;
        int tmp=0;
        int n=nums.size();
        if (n==0) {
        	return ret;
		}
        for (int i=1; i<n; ++i) {
            if (nums[i]!=nums[i-1]+1) {
                str="";
                //str+=(char)(nums[tmp]+'0');
                Add(str,abs(nums[tmp]),nums[tmp]<0);
                if (i-1!=tmp) {
                    str+="->";
                    //str+=(char)(nums[i-1]+'0');
                    Add(str,abs(nums[i-1]),nums[i-1]<0);
                }
                ret.push_back(str);
                tmp=i;
            }
        }
        str="";
        //str+=(char)(nums[tmp]+'0');
        Add(str,abs(nums[tmp]),nums[tmp]<0);
        if (n-1!=tmp) {
        	str+="->";
        	//str+=(char)(nums[n-1]+'0');
        	Add(str,abs(nums[n-1]),nums[n-1]<0);
		}
		ret.push_back(str);
        return ret;
    }
};

int main()
{
	vector<int> A={-5,-4,-2,-1,0,2,3,9,10,159,160};
	vector<string> B;
	Solution S;
	B=S.summaryRanges(A);
	for (int i=0; i<B.size(); i++)
		cout <<B[i] <<endl;
	return 0;
}
