//https://leetcode-cn.com/problems/valid-number/
#include <string>
#include <cstdio>
using namespace std;

class Solution {
public:
    bool isNumber(string s) {
        double a;
        char c[10086];
        for (int i=0; i<s.length(); i++)
        	c[i]=s[i];
        return (sscanf(c,"%lf",&a));
    }
};

int main()
{
	Solution S;
	printf("%d\n",S.isNumber("."));
	return 0;
}
