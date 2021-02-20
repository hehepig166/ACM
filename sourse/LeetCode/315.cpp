//https://leetcode-cn.com/problems/count-of-smaller-numbers-after-self/
#include <bits/stdc++.h>
using namespace std;

#define N 10005

class segment_tree {
    #define LX (X<<1)
    #define RX ((X<<1)|1)
    #define M ((L+R)>>1)
    int cnt[N<<4];

public:
    void build(int X, int L, int R) {
        if (L==R) {
            cnt[X]=0;
            return;
        }
        build(LX,L,M);
        build(RX,M+1,R);
        cnt[X]=cnt[LX]+cnt[RX];
    }

    void add(int X, int L, int R, const int &t) {  //s[t]++
        if (R<t || t<L) {
            return;
        }
        if (L==t && R==t) {
        	cnt[X]++;
        	return;
        }
        add(LX,L,M,t);
        add(RX,M+1,R,t);
		cnt[X]=cnt[LX]+cnt[RX];
    }

    int query(int X, int L, int R, const int &l, const int &r) {    //s[l]+..+s[r]
        if (R<l || r<L) {
            return 0;
        }
        if (l<=L && R<=r) {
            return cnt[X];
        }
        return query(LX,L,M,l,r)+query(RX,M+1,R,l,r);
    }
};

class Solution {
public:
    vector<int> countSmaller(vector<int>& nums) {
    	int d=N;
    	
        int n=nums.size();
        vector<int> counts(n);

        segment_tree S;
        S.build(1,0,d<<1);

        for (int i=n-1; i>=0; i--) {
            counts[i]=S.query(1,0,d<<1,0,nums[i]+d-1);
            S.add(1,0,d<<1,nums[i]+d);
        }

        return counts;
    }
};

int main()
{
	vector<int> A={},ans;
	Solution S;
	ans=S.countSmaller(A);
	for (auto i: ans) {
		cout <<i <<endl;
	}
	return 0;
}
