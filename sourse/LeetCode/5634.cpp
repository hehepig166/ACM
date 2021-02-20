//https://leetcode-cn.com/contest/biweekly-contest-43/problems/maximum-score-from-removing-substrings/
#include <vector>
#include <string>
#include <iostream>
using namespace std;

class Solution {
public:
	
    int maximumGain(string s, int x, int y) {
    	int Ans=0;
        int n=s.length();
    	char L,R;
    	if (x>y) {
    		L='a',R='b';
		}
		else {
			swap(x,y);
			L='b',R='a';
		}
		
		vector<int> l(n),r(n),f(n);
		for (int i=0; i<n; i++) {
			l[i]=i-1;
			r[i]=i+1;
		}
		
		
		for (int i=1; i<n; i=r[i]) {
			if (s[i]==R && l[i]>=0 && s[l[i]]==L) {
				f[i]=f[l[i]]=1;
				Ans+=x;
				if (l[l[i]]>=0) r[l[l[i]]]=r[i];
				if (r[i]<n) l[r[i]]=l[l[i]];
			}
			if (i==n-1)
				break;
		}
		
		int tmp=0;
		while (tmp<n && f[tmp]) tmp++;
		if (tmp==n)
			return Ans;
		for (int i=r[tmp]; i<n; i=r[i]) {
			if (s[i]==L && l[i]>=0 && s[l[i]]==R) {
				Ans+=y;
				if (r[i]<n) l[r[i]]=l[l[i]];
			}
			if (i==n-1)
				break;
		}
		
		return Ans;
		
    }
};

int main()
{
	Solution S;
	string s="ababababababab";
	cout <<S.maximumGain(s,9421,8003) <<endl;
	return 0;
}
