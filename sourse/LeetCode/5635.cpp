//https://leetcode-cn.com/contest/biweekly-contest-43/problems/construct-the-lexicographically-largest-valid-sequence/
#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
	
	int dfs(int n,int x,char f[30],vector<int> &a) {
		int len=n*2-1;
		for (int i=n; i; i--) {
			if (!f[i] && (x+i<len && a[x+i]==0 || i==1)) {
				f[i]=1;
				a[x]=i;
				if (i!=1) a[x+i]=i;
				
				int tmp=x;
				while (tmp<len && a[tmp])
					tmp++;
				if (tmp==len)
					return 1;
				
				if (dfs(n,tmp,f,a)) {
					return 1;
				}
				
				f[i]=0;
				a[x]=0;
				if (i!=1) a[x+i]=0;
			}
		}
		return 0;
	}
	
    vector<int> constructDistancedSequence(int n) {
        vector<int> ret(n*2-1);
        char f[30]={0};
        dfs(n,0,f,ret);
        return ret;
    }
};

int main()
{
	Solution S;
	vector <int> ans=S.constructDistancedSequence(4);
	for (int i=0; i<ans.size(); i++)
		cout <<ans[i] <<" ";
	cout <<endl;
	return 0;
}
