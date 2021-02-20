//https://leetcode-cn.com/problems/sliding-window-maximum/
#include <vector>
#include <queue>
#include <algorithm>
#include <iostream>
using namespace std;

class Solution {
public:

    struct node {
        int id;
        int val;
        node(int x = 100, int y = 100) {
            id = x;
            val = y;
        }
    };


    struct cmp {
        bool operator()(const node& x, const node& y) {
            return x.val == y.val ? x.id < y.id : x.val < y.val;
        }
    };

    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        priority_queue<node, vector<node>, cmp> q;
        vector<int> ret;

        for (int i = 0; i < k; ++i) {
            q.push(node(i, nums[i]));
        }

        ret.push_back(q.top().val);

        for (int R = k, L = 1; R < nums.size(); ++R, ++L) {
            while (!q.empty() && q.top().id < L) {
                q.pop();
            }
            q.push(node(R, nums[R]));
            ret.push_back(q.top().val);
        }

        return ret;
    }
};

int main()
{
    vector<int> nums = { 1,3,-1,-3,5,3,6,7 }, ans;
    Solution S;
    ans = S.maxSlidingWindow(nums, 3);
    for (int i = 0; i < ans.size(); ++i) {
        cout << ans[i] << endl;
    }
    return 0;
}
