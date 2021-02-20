//https://leetcode-cn.com/problems/bitwise-and-of-numbers-range/
#include <cstdio>
#include <iostream>
using namespace std;

class Solution {
public:
    int rangeBitwiseAnd(int m, int n) {
        int Ans=0;
        int xm=m,xn=n,tmp=1;
        while (xm!=xn) {
            xm>>=1;
            xn>>=1;
            tmp<<=1;
        }
        Ans=xn*tmp;
        return Ans;
    }
};

int main()
{
	Solution S;
	int n,m,ans;
	cin >>n >>m;
	cout <<S.rangeBitwiseAnd(n,m) <<endl;
	ans=n;
	for (int i=n+1; i<=m; i++)
		ans&=i;
	cout <<ans <<endl;
	return 0;
}
