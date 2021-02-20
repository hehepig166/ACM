//https://leetcode-cn.com/problems/evaluate-division/

#include <iostream>
#include <vector>
#include <string>
#include <map>
using namespace std;

class Solution {

typedef pair<string,double> edge;

private:
	map<string,vector<edge>> M;
	map<string,int> vis;
	inline void Add(string x, string y, double v) {
		M[x].push_back(edge(y,v));
		M[y].push_back(edge(x,1.0/v));
	}
	
public:
	
	
	
	void build(vector<vector<string>>& equations, vector<double>& values) {
		vector<vector<string>>::iterator itequ = equations.begin();
		vector<double>::iterator itval = values.begin();
		for (; itequ!=equations.end(); itequ++,itval++) {
			Add((*itequ)[0],(*itequ)[1], (*itval));
		}
	}
	
	double Solve(const string &startstr, const string &endstr) {
		
		//cout <<startstr <<"\t=>\t" <<endstr <<endl;
		
		if (startstr==endstr) {
			return M.find(startstr)!=M.end() ? 1 : -1;
		}
		
		vis[startstr]=1;
		
		double tmp;
		vector<edge>::iterator it = M[startstr].begin(),ed=M[startstr].end();
		for (; it!=ed; it++)
			if (vis.find((*it).first) == vis.end()) {
				tmp=Solve((*it).first,endstr);
				if (tmp!=-1) {
					return tmp*(*it).second;
				}
			}
		
		return -1;
	}
	
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        vector<double> ret;
        
        build(equations,values);
        
        vector<vector<string>>::iterator it = queries.begin();
        for (; it!=queries.end(); it++) {
        	vis.clear();
        	ret.push_back(Solve((*it)[0],(*it)[1]));
		}
        
        return ret;
    }

};

int main()
{
	
	Solution SS;
	
	vector<vector<string>> equations;
	vector<double> values;
	vector<vector<string>> queries;
	
	vector<string> tmp;
	vector<double> ans;
	
	tmp.clear();
	tmp.push_back("a");
	tmp.push_back("b");
	equations.push_back(tmp);
	values.push_back(2);
	
	tmp.clear();
	tmp.push_back("b");
	tmp.push_back("c");
	equations.push_back(tmp);
	values.push_back(3);
	
	tmp.clear();
	tmp.push_back("x");
	tmp.push_back("x");
	queries.push_back(tmp);
	
	
	ans=SS.calcEquation(equations,values,queries);
	vector<double>::iterator it = ans.begin();
	for (; it!=ans.end(); it++) {
		cout <<(*it) <<endl;
	}
	
	return 0;
}
