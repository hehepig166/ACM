#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
	
	int solve(vector<int> &nums, int k) {
		int n=nums.size();
		int tmp,cnt,ret;
		
		ret=0;
		
		for (int i=0; i<k; i++) {
            vector<int> a(1024);
            
            cnt=0;
            for (int j=i; j<n; j+=k) {
                a[nums[j]]++;
                cnt++;
            }
            
            tmp=0;
            for (int j=0; j<1024; j++)
                tmp=max(tmp,a[j]);
            
            ret+=(cnt-tmp);
        }
        return ret;
	}
	
    int minChanges(vector<int>& nums, int k) {
        int n=nums.size(),tmp,cnt,ret;
        
        tmp=0;
        for (int i=0; i<k; i++)
        	tmp^=nums[i];
        	
        if (tmp==0) {
        	return solve(nums,k);
		}
		else {
			int tt=0,ttt;
			vector<int> q;
			for (int t=0; t<k; t++) {
				for (int i=0; i<k; i++) if (i!=t) {
					vector<int> a(1024);
					
					cnt=0;
					for (int j=i; j<n; j+=k) {
						a[nums[j]]++;
						cnt++;
					}
					
					ttt=0;
					for (int j=0; j<1024; j++) {
						if (ttt<a[j]) {
							ttt=a[j];
							q.clear();
							q.emplace_back(a[j]);
						}
						else if (ttt==a[j]) {
							q.emplace_back(a[j]);
						}
					}
					
					ret+=(cnt-ttt);
				}
				
			}
		}
        
        
    }
};

int main()
{
	Solution S;
	vector<int> A={1,2,4,1,2,5,1,2,6};
	cout<<S.minChanges(A,3);
	return 0;
}
