//https://leetcode-cn.com/problems/insert-interval/submissions/
#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>> ret;
        int n,L,R,Lx,Rx;
        n=intervals.size();
        L=n;
        R=-1;

        for (int i=0; i<n; i++) {
            if (intervals[i][1]>=newInterval[0]) {
                L=i;
                break;
            }
            else {
                ret.push_back(intervals[i]);
            }
        }

        Lx=(L==n) ? newInterval[0] : min(newInterval[0],intervals[L][0]);
        Rx=newInterval[1];
        
        for (int i=L; i<n; i++) {
            if (intervals[i][0]>newInterval[1]) {
                break;
            }
            else {
                Rx=max(Rx,intervals[i][1]);
                R=i;
            }
        }
        ret.push_back(vector<int> {Lx,Rx});
        
        
        for (int i=R+1; i<n; i++) {
        	if (intervals[i][0]>newInterval[1])
            	ret.push_back(intervals[i]);
        }
        
        return ret;

        
    }
};

int main()
{
	Solution S;
	vector<vector<int>> a={{1,5}},ans;
	vector<int> b={6,8};
	ans=S.insert(a,b);
	return 0;
}
