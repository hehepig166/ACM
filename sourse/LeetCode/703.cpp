#include <bits/stdc++.h>
using namespace std;

class KthLargest {
    vector<int> A;
    int K;
public:
    KthLargest(int k, vector<int>& nums) {
        K=k;
        A=nums;
        sort(A.begin(),A.end());
    }
    
    int add(int val) {
        int n=A.size(),p,tmp;
        if (n==0) {
            A.push_back(val);
            return val;
        }
        for (p=0; p<n; p++) {
            if (A[p]>=val) {
                break;
            }
        }
        if (p==n) {
        	A.push_back(val);
		}
		else {
    	   	tmp=A[p];
    	    A[p]=val;
    	    for (p++; p<n; p++) {
    	        swap(tmp,A[p]);
    	    }
    	    A.push_back(tmp);
    	}
        return A[n+1-K];
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */

int main()
{
	vector<int> V={4,5,8,2};
	KthLargest S(3,V);
	cout <<S.add(-3) <<endl;
	cout <<S.add(-2) <<endl;
	cout <<S.add(-4) <<endl;
	cout <<S.add(0) <<endl;
	cout <<S.add(4) <<endl;
	
	
	return 0;
}
