//https://leetcode-cn.com/problems/similar-string-groups/
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    int f[105],vis[105];
    int Fa(int x) {return f[x]==x ? x : f[x]=Fa(f[x]);}

    bool check(string &a, string &b) {
        static int p[3],cnt,len;
        len=a.length();
        cnt=0;
        for (int i=0; i<len; i++) {
            if (a[i]!=b[i]) {
                if (++cnt>2) {
                    return 0;
                }
                p[cnt]=i;
            }
        }
        return (a[p[1]]==b[p[2]] || cnt==0);
    }

    int numSimilarGroups(vector<string>& strs) {
        int fi,fj,n=strs.size(),ans=0;

        for (int i=0; i<n; i++) {
            f[i]=i;
            vis[i]=0;
        }

        for (int i=0; i<n; i++) {
            for (int j=i+1; j<n; j++) {
                fi=Fa(i),fj=Fa(j);
                if (fi==fj || !check(strs[i],strs[j])) {
                    continue;
                }
                f[fi]=fj;
                Fa(fi);
            }
        }

        for (int i=0; i<n; i++) {
            fi=Fa(i);
            ans+=(!vis[fi]);
            vis[fi]=1;
        }

        return ans;
    }
};

int main()
{
	Solution S;
	vector<string> A={"koqnn","knnqo","noqnk","nqkon"};
	cout <<S.numSimilarGroups(A) <<endl;
	return 0;
}
