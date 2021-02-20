#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int subarraysWithKDistinct(vector<int>& A, int K) {
    	vector<int> f(20005,0);
        int cnt;
        int n=A.size();
        int L,R,ans1,ans2;
        
        f[A[0]]++;
        cnt=1;
		L=R=ans1=0;
        while (R<n) {
            while (cnt<=K && R<n) {
            	ans1+=(R-L+1);	//
                R++;
                if (R==n)
                	break;
                f[A[R]]++;
                cnt+=(f[A[R]]==1);
            }
            if (L<=R && L<n) {
                f[A[L]]--;
                cnt-=(f[A[L]]==0);
                L++;
            }
        }

		K--;
		cnt=1;
		L=R=ans2=0;
		f.clear();
		f.resize(20005);
		f[A[0]]=1;
		while (R<n) {
            while (cnt<=K && R<n) {
            	ans2+=(R-L+1);	//
                R++;
                if (R==n)
                	break;
                f[A[R]]++;
                cnt+=(f[A[R]]==1);
            }
            if (L<=R && L<n) {
                f[A[L]]--;
                cnt-=(f[A[L]]==0);
                L++;
            }
        }

        return ans1-ans2;
    }
};

int main()
{
	Solution S;
	vector<int> A={1,2};
	cout <<S.subarraysWithKDistinct(A,1) <<endl;
	
}
