//https://leetcode-cn.com/problems/number-of-students-unable-to-eat-lunch/
#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    int countStudents(vector<int>& students, vector<int>& sandwiches) {
        int stu[2]={0},sand[2]={0};
        for (int i=0; i<students.size(); i++) {
            stu[students[i]]++;
        }
        for (int i=0; i<sandwiches.size(); i++) {
            if (++sand[sandwiches[i]] > stu[sandwiches[i]])
                return (students.size()-sand[0]-sand[1]+1);
        }
        return 0;
    }
};

int main()
{
	Solution S;
	vector<int> students={1,1,1,0,0,1},sandwiches={1,0,0,0,1,1};
	cout <<S.countStudents(students,sandwiches) <<endl;
	return 0;
}
