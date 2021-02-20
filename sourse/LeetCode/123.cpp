//https://leetcode-cn.com/problems/best-time-to-buy-and-sell-stock-iii/
#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        int Min,Max,Ans;
        vector<int> Lmax(n),Rmax(n);

        Min=prices[0];
        Lmax[0]=0;
        for (int i=1; i<n; i++) {
            Lmax[i]=max(Lmax[i-1],prices[i]-Min);
            Min=min(Min,prices[i]);
        }

        Max=prices[n-1];
        Rmax[n-1]=0;
        for (int i=n-2; i>=0; i--) {
            Rmax[i]=max(Rmax[i+1],Max-prices[i]);
            Max=max(Max,prices[i]);
        }

        Ans=max(0,Rmax[0]);
        for (int i=1; i<n; i++) {
            Ans=max(Ans,Lmax[i-1]+Rmax[i]);
        }

        return Ans;
    }
};

int main()
{
	vector<int> A={3,3,5,0,0,3,1,4};
	Solution S;
	cout <<S.maxProfit(A) <<endl;
	return 0;
}
