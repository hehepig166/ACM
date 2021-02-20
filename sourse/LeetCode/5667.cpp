#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int n;
    
    vector<bool> canEat(vector<int>& candiesCount, vector<vector<int>>& queries) {
        int n=candiesCount.size();
        vector<long long> s(n+5);
        s[0]=0;
        for (int i=0; i<n; i++) {
            s[i+1]=s[i]+candiesCount[i];
        }
        
        vector<bool> ret;
        
        long long t;
        
        for (auto I: queries) {
            t=1ll*I[2]*(I[1]+1);
            ret.emplace_back(s[I[0]]<t && s[I[0]+1]>=I[1]);
        }
        
        return ret;
    }
};

int main()
{
	Solution S;
	vector<int> A={46,5,47,48,43,34,15,26,11,25,41,47,15,25,16,50,32,42,32,21,36,34,50,45,46,15,46,38,50,12,3,26,26,16,23,1,4,48,47,32,47,16,33,23,38,2,19,50,6,19,29,3,27,12,6,22,33,28,7,10,12,8,13,24,21,38,43,26,35,18,34,3,14,48,50,34,38,4,50,26,5,35,11,2,35,9,11,31,36,20,21,37,18,34,34,10,21,8,5};
	vector<bool> ans;
	vector<vector<int>> B={{85,54,42}};
	ans=S.canEat(A,B);
	for (auto I: ans) {
		cout <<I <<endl;
	}
	return 0;
}
/*
[46,5,47,48,43,34,15,26,11,25,41,47,15,25,16,50,32,42,32,21,36,34,50,45,46,15,46,38,50,12,3,26,26,16,23,1,4,48,47,32,47,16,33,23,38,2,19,50,6,19,29,3,27,12,6,22,33,28,7,10,12,8,13,24,21,38,43,26,35,18,34,3,14,48,50,34,38,4,50,26,5,35,11,2,35,9,11,31,36,20,21,37,18,34,34,10,21,8,5]
[[85,54,42]]
*/
