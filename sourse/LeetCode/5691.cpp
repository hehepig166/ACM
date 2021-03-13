#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minOperations(vector<int>& nums1, vector<int>& nums2) {
        int c[2][7]={0};
        for (int i: nums1) c[0][i]++;
        for (int i: nums2) c[1][i]++;
        int s1=0,s2=0,d,ans=0,tmp;
        for (int i=1; i<=6; i++)
            (s1+=c[0][i]*i),(s2+=c[1][i]*i);
        
        if (s1>s2) {
            d=s1-s2;
            for (int i=5; i>0; i--) {
                tmp=(d/i)+(d%i>0);
                if (c[0][i+1]+c[1][6-i] >= tmp) {
                    ans+=tmp;
                    return ans;
                }
                else {
                    d-=(c[0][i+1]+c[1][6-i])*i;
                    ans+=(c[0][i+1]+c[1][6-i]);
                }
            }
            return -1;
                
        }
        else if (s1<s2) {
            d=s2-s1;
            for (int i=5; i>0; i--) {
                tmp=(d/i)+(d%i>0);
                if (c[1][i+1]+c[0][6-i] >= tmp) {
                    ans+=tmp;
                    return ans;
                }
                else {
                    d-=(c[1][i+1]+c[0][6-i])*i;
                    ans+=(c[1][i+1]+c[0][6-i]);
                }
            }
            return -1;
        }
        else {
            return 0;
        }
    }
};

int main()
{
	vector<int> A={5,6,4,3,1,2},B={6,3,3,1,4,5,3,4,1,3,4};
	Solution S;
	cout <<S.minOperations(A,B) <<endl;
	return 0;
}

/*
[5,6,4,3,1,2]
[6,3,3,1,4,5,3,4,1,3,4]
*/
