//https://leetcode-cn.com/problems/utf-8-validation/
#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
	
	int len(int x) {
		int ret=0;
		if ((x^0b11110000)<=0b00000111) return 4;
		if ((x^0b11100000)<=0b00001111) return 3;
		if ((x^0b11000000)<=0b00011111) return 2;
		if ((x&0b10000000)==0) return 1;
		return 0;
	}
	
    bool validUtf8(vector<int>& data) {
        for (int pt=0; pt<data.size(); pt++) {
        	int n=len(data[pt]);
        	if (n==0) {
        		return 0;
			}
			else if (n==1) {
				continue;
			}
			else if (pt+n<=data.size()) {
				for (int i=1; i<n; i++) {
					pt++;
					if ((data[pt]&0b10000000)!=0b10000000) {
						return 0;
					}
				}
				continue;
			}
			else {
				return 0;
			}
		}
		return 1;
    }
};

int main()
{
	Solution S;
	vector<int> a={248,130,130,130};
	cout <<S.validUtf8(a) <<endl;
	return 0;
}
