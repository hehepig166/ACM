#include <bits/stdc++.h>
using namespace std;

class NumArray {
#define LX (X<<1)
#define RX ((X<<1)|1)
#define M ((L+R)>>1)
    static const int N = 30001;
    int s[N << 2];
    int n;

    void _build(int X, int L, int R, vector<int>& nums) {
        if (L == R) {
            s[X] = L<n ? nums[L] : 0;
            return;
        }
        _build(LX, L, M, nums);
        _build(RX, M + 1, R, nums);
        s[X] = s[LX] + s[RX];
    }

    void _update(int X, int L, int R, const int& t, const int& v) {   //[t]=v
        if (t < L || R < t) {
            return;
        }
        if (L == t && R == t) {
            s[X] = v;
            return;
        }
        _update(LX, L, M, t, v);
        _update(RX, M + 1, R, t, v);
        s[X] = s[LX] + s[RX];
    }

    int _query(int X, int L, int R, const int& l, const int& r) {
        if (r < L || R < l) {
            return 0;
        }
        if (l <= L && R <= r) {
            return s[X];
        }
        return _query(LX, L, M, l, r) + _query(RX, M + 1, R, l, r);
    }

public:
    NumArray(vector<int>& nums) {
        n = nums.size();
        _build(1, 0, n, nums);
    }

    void update(int index, int val) {
        _update(1, 0, n, index, val);
    }

    int sumRange(int left, int right) {
        return _query(1, 0, n, left, right);
    }
};

int main()
{
	vector<int> A={-1};
	
	NumArray* obj=new NumArray(A);
	cout <<obj->sumRange(0,0) <<endl;
	obj->update(0,1);
	cout <<obj->sumRange(0,0);
	return 0;
}

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */
