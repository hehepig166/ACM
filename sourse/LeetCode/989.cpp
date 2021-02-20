#include <cstdio>
#include <vector>
using namespace std;

class Bignumber {
public:
    vector<int> a;

public:
    Bignumber(long long A=0) {
        a.clear();
        for (; A; A/=10) {
            a.emplace_back(A%10);
        }
    }
    Bignumber(const vector<int> &A) {
        for (int i=A.size()-1; i>=0; i--) {
        	a.emplace_back(A[i]);
		}
    }

    int len() {
        return a.size();
    }

    Bignumber operator+ (Bignumber &B) {
        Bignumber A=*this;
        Bignumber C;
        int c=0,tmp,i;
        for (i=0; i<A.len() && i<B.len(); i++) {
            tmp=A.a[i]+B.a[i]+c;
            c=tmp/10;
            C.a.emplace_back(tmp%10);
        }
        for (; i<A.len(); i++) {
            tmp=A.a[i]+c;
            c=tmp/10;
            C.a.emplace_back(tmp%10);
        }
        for (; i<B.len(); i++) {
            tmp=B.a[i]+c;
            c=tmp/10;
            C.a.emplace_back(tmp%10);
        }
        if (c>0) {
            C.a.emplace_back(c);
        }
        return C;
    }

};

class Solution {
public:
    vector<int> addToArrayForm(vector<int>& _A, int _K) {
        Bignumber A(_A),B(_K),C;
        C=A+B;
        vector<int> ret;
        if (C.len()==0) {
        	ret.emplace_back(0);
		}
        else for (int i=C.len()-1; i>=0; i--) {
        	ret.emplace_back(C.a[i]);
		}
        return ret;
    }
};

int main()
{
	vector<int> A={2,1,5},C;
	Solution S;
	C=S.addToArrayForm(A,806);
	for (int i=0; i<C.size(); i++) {
		printf("%d ",C[i]);
	}
	return 0;
}
