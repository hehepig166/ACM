#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
	
	string keyToStr(const int K) {
		string ret;
		for (int i=0; i<26; i++)
			if (K&(1<<i))
				ret+=char(i+'a');
		return ret;
	}
	
    vector<int> findNumOfValidWords(vector<string>& words, vector<string>& puzzles) {
        vector<int> cntw(1<<26);
        vector<int> answer;

        //获取不同键值的数量
        for (string W: words) {
            int key=0;
            for (int i=W.length()-1; i>=0; i--)
                key|=(1<<(W[i]-'a'));
            cntw[key]++;
        }

        for (string P: puzzles) {
            int key=0, cnt=cntw[1<<(P[0]-'a')];
            for (int i=P.length()-1; i>=0; i--)
                key|=(1<<(P[i]-'a'));
            
            for (int tmp=key; tmp>0; tmp=((tmp-1)&key))
                cnt+=cntw[tmp|(1<<(P[0]-'a'))];
            
            answer.push_back(cnt);
        }

        return answer;
    }
};

int main()
{
	Solution S;
	vector<string> Ws={"aaaa","asas","able","ability","actt","actor","access"},Ps={"aboveyz","abrodyz","abslute","absoryz","actresz","gaswxyz"};
	vector<int> ans;
	ans=S.findNumOfValidWords(Ws,Ps);
	return 0;
}
