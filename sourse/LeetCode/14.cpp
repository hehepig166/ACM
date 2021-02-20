//https://leetcode-cn.com/problems/longest-common-prefix/
#include <cstdio>

char * longestCommonPrefix(char ** strs, int strsSize){

    char *ret= (char *)(new(char[205]));
    //static char ret[205];

    if (strsSize==0) {
        ret[0]=0;
        return ret;
    }

    int len=0;
    for (; strs[0][len]!=0; len++) {
        ret[len]=strs[0][len];
        for (int i=1; i<strsSize; i++) {
            if (strs[i][len]!=ret[len]) {
                ret[len]=0;
                return ret;
            }
        }
        ret[len+1]=0;
    }
    return ret;
}

int main()
{
	
	return 0;
}
