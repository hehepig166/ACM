#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int closestCost(vector<int>& baseCosts, vector<int>& toppingCosts, int target) {
        int n=baseCosts.size(),m=toppingCosts.size();
        int ans=0,d;
        int T=20005;
        vector<int> f1(30005+1,0);
        
        for (int i=0; i<n; i++)
            f1[baseCosts[i]]=1;
        
        for (int i=0; i<m; i++)
        	for (int t=1; t<=2; t++)
        		for (int k=T-1; k>0; k--) if (f1[k])
        			if (k+toppingCosts[i]<=T)
        				f1[k+toppingCosts[i]]=1;
		
        
        
        d=99999999;
        for (int i=T; i; i--)
            if (f1[i] && abs(target-i)<=d)
            {
                d=abs(target-i);
                ans=i;
            }
        
        return ans;
    }
};

int main()
{
	vector<int> A={2,3},B={4,5,100};
	Solution S;
	cout <<S.closestCost(A,B,18) <<endl;
    return 0;
}
