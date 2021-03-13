#include <bits/stdc++.h>
using namespace std;

class Solution {
#define I points[i]
public:
    int nearestValidPoint(int x, int y, vector<vector<int>>& points) {
        int n=points.size();
        int mind=99999,mid=-1;
        for (int i=0; i<n; i++) {
            
            if (I[0]==x || I[1]==y) {
                if (mid==-1) {
                    mid=i;
                    mind= abs(x-I[0])+abs(y-I[1]);
                }
                else if ((abs(x-I[0]+abs(y-I[1]))<mind)) {
                    mind=abs(x-I[0])+abs(y-I[1]);
                    mid=i;
                }
            }
        }
        return mid;
    }
};

int main()
{
	
}
