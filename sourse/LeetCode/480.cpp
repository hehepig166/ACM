#include <bits/stdc++.h>
using namespace std;

class DualHeap {
    //大根堆，较小一半
    priority_queue<int> small;

    //小根堆，较大一般
    priority_queue<int, vector<int>, greater<int>> large;

    //哈希表，记录 延迟删除 的元素，key 为元素，value 为需要删除的次数
    unordered_map<int, int> delayed;

    int k;

    // small 和 large 当前包含的元素个数，（扣除被延迟删除的元素）
    int smallSize, largeSize;

public:
    DualHeap(int _k): k(_k), smallSize(0), largeSize(0) {}

private:

    //不断弹出 heap 堆顶元素，并更新哈希表
    template<typename T>
    void prune(T &heap) {
        while (!heap.empty()) {
            int num=heap.top();
            if (delayed.count(num)) {
                --delayed[num];
                if (!delayed[num]) {
                    delayed.erase(num);
                }
                heap.pop();
            }
            else {
                break;
            }
        }
    }

    //调整 small 和 large 中元素个数，使二者元素个数满足要求
    void makeBalance() {
        if (smallSize > largeSize+1) {
            large.push(small.top());
            small.pop();
            --smallSize;
            ++largeSize;
            
            //small堆顶元素被移除，需要 prune
            prune(small);
        }
        else if (smallSize < largeSize) {
            small.push(large.top());
            large.pop();
            ++smallSize;
            --largeSize;

            prune(large);
        }
    }

public:
    void insert(int num) {
        if (small.empty() || num<=small.top()) {
            small.push(num);
            ++smallSize;
        }
        else {
            large.push(num);
            ++largeSize;
        }
        makeBalance();
    }

    void erase(int num) {
        ++delayed[num];
        if (num<=small.top()) {
            --smallSize;
            if (num==small.top()) {
                prune(small);
            }
        }
        else {
            --largeSize;
            if (num==large.top()) {
                prune(large);
            }
        }
        makeBalance();
    }

    double getMedian() {
        return k&1 ? small.top() : ((double)small.top()+large.top())/2;
    }
};

class Solution {
public:
    vector<double> medianSlidingWindow(vector<int> &nums, int k) {
        DualHeap dh(k);
        for (int i=0; i<k; ++i) {
            dh.insert(nums[i]);
        }
        vector<double> ans={dh.getMedian()};
        for (int i=k; i<nums.size(); ++i) {
            dh.insert(nums[i]);
            dh.erase(nums[i-k]);
            ans.push_back(dh.getMedian());
        }
        return ans;
    }
};

int main()
{
    
}