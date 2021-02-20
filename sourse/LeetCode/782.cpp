//https://leetcode-cn.com/problems/transform-to-chessboard/
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    long long hash(vector<int> &X) {
        long long ret=0;
        for (auto I:X) {
            ret=(ret<<1)|I;
        }
        return ret;
    }

    int solve(vector<int> &f, int c[]) {
        int num1=2147483647,num2=2147483647,n=f.size();
        if (c[0]==c[1] || c[1]==c[0]+1) {   // 101 or 1010
            num1=0;
            for (int i=0; i<n; i++) {
                num1+= !((i&1) ^ f[i]);
            }
            num1>>=1;
        }
        if (c[0]==c[1] || c[1]==c[0]-1) {  // 010 or 0101
            num2=0;
            for (int i=0; i<n; i++) {
                num2+=((i&1) ^ f[i]);
            }
            num2>>=1;
        }
        return min(num1,num2);
    }

    int movesToChessboard(vector<vector<int>>& board) {
        int cnt=0,n=board.size();
        int c[2]={0};   // f ÖÐ 01 ¸öÊý
        long long id[5]={0},h;
        vector<int> f;
        for (int i=0; i<n; i++) {
            h=hash(board[i]);
            if (cnt>0 && id[0]==h) {
                f.push_back(0);
                c[0]++;
                continue;
            }
            else if (cnt>1 && id[1]==h) {
                f.push_back(1);
                c[1]++;
                continue;
            }
            else {
                id[cnt++]=h;
                if (cnt<=2) {
                    f.push_back(cnt-1);
                    c[cnt-1]++;
                }
                else {
                    return -1;
                }
            }
        }
        if (abs(c[0]-c[1])>1) {
            return -1;
        }
        
        
        int ans=0;
        ans+=solve(f,c);
        
        if (id[0]&id[1]) {
        	return -1;
		}
		c[0]=c[1]=0;
        for (int i=0; i<n; i++) {
        	c[board[0][i]]++;
		}
		if (abs(c[0]-c[1])>1) {
			return -1;
		}
		ans+=solve(board[0],c);
		
		return ans;

    }
};

int main()
{
	//vector<vector<int>> A={{0,1,1,0},{0,1,1,0},{1,0,0,1},{1,0,0,1}};
	//vector<vector<int>> A={{1,0},{0,1}};
	vector<vector<int>> A={{1,1,1,1},{1,1,1,1},{0,0,0,0},{0,0,0,0}};
	Solution S;
	cout <<S.movesToChessboard(A) <<endl;
	return 0;
}
