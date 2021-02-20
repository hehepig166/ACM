#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minimumBoxes(int n) {
        long long S=0,tmp=0,ans=0;
        for (long long i=1; S+tmp<=n; i++) {
        	tmp+=i;
            if (S+tmp<=n) {
            	S+=tmp;
                ans=tmp;
            }
            else {
            	break;
			}
        }
        
        for (long long i=1; S<n; i++) {
        	S+=i;
        	ans++;
		}
        return ans;
    }
};

int main()
{
	Solution S;
	cout <<S.minimumBoxes(51) <<endl;
	return 0;
}
