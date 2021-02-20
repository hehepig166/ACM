//https://leetcode-cn.com/problems/maximum-binary-string-after-change/
#include <string>
#include <iostream>
using namespace std;

class Solution {
public:
    string maximumBinaryString(string binary) {
        int n=binary.length();
        int s[2]={0};
        for (int i=0; i<n; i++)
            s[binary[i]-'0']++;
        
        string ret(n,'1');
        if (s[0]) ret[s[0]-1]='0';
        return ret;
    }
};


char * maximumBinaryString(char * binary){
	int n=strlen(binary);
	int s[2]={0},i;
	static char ret[100005];
	for (i=0; i<n; i++)
		++s[binary[i]-'0'];
	
	for (i=0; i<s[0]; ++i)
		ret[i]='1';
	--i;
	if (s[0])
		ret[i]='0';
	for (++i; i<n; ++i)
		ret[i]='1';
	ret[i]='\0';
	return ret;
}

int main()
{
	char binary[100]="01111001100000110010";
	cout << maximumBinaryString(binary) <<endl;
	return 0;
}
