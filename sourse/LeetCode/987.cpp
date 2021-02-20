#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxTurbulenceSize(vector<int>& a) {
        int n=a.size();
        if (n<=1) {
            return n;
        }
        int ans,s;
        if (a[0]!=a[1]) {
            ans=s=2;
        }
        else {
            ans=s=1;
        }

        for (int i=2; i<n; i++) {
            if (a[i]!=a[i-1] && a[i-1]!=a[i-2] && ((a[i]>a[i-1])^(a[i-1]>a[i-2]))) {
                ans=max(ans,++s);
            }
            else {
                ans=max(ans,s=(a[i]!=a[i-1])+1);
            }
        }
        return ans;
    }
};

int main()
{
	vector<int> a={100};
	Solution S;
	cout <<S.maxTurbulenceSize(a);
	return 0;
}
