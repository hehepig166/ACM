//https://leetcode-cn.com/problems/bricks-falling-when-hit/
#include <vector>
#include <cstdio>
#include <iostream>
using namespace std;

class Solution {
public:
	#define MAX 200
	#define ID(x,y) ((x-1)*(MAX+1)+y)	//x,y:1~MAX
	inline bool OK(int x,int y){return ((x)>0 && (x)<=n && (y)>0 && (y)<=m);}
	
	int n,m,q,num,tmp;
	int f[ID(MAX,MAX)]={0},sum[ID(MAX,MAX)]={0};
	int graph[ID(MAX,MAX)]={0};
	int Fx[4][2]={{-1,0},{1,0},{0,1},{0,-1}};
	
	int Fa(int x) {
		if (f[x]==x) {
			return x;
		}
		f[x]=Fa(f[x]);
		sum[f[x]]+=sum[x];
		sum[x]=0;
		return f[x];
	}
	
	void merge(int x, int y) {	//x->y
		int rx=Fa(x),ry=Fa(y);
		if (rx==ry) {
			return ;
		}
		f[rx]=ry;
		sum[ry]+=sum[rx];
		sum[rx]=0;
	}
	
    vector<int> hitBricks(vector<vector<int>>& grid, vector<vector<int>>& hits) {    	
        n=grid.size();
        m=grid[0].size();
        q=hits.size();
        num=0;
        vector<int> ret(q);
        
        for (int i=1,id; i<=n; i++) {
        	for (int j=1; j<=m; j++) {
        		id=ID(i,j);
        		f[id]=id;
        		num+=sum[id]=graph[id]=grid[i-1][j-1];
			}
		}
        
        for (auto I: hits) if (grid[I[0]][I[1]]) {
        	graph[ID(I[0]+1,I[1]+1)]=0;
		}
		
  		for (int i=1,id; i<=n; i++) {
			for (int j=1; j<=m; j++) {
				id=ID(i,j);
				if (graph[id]) {
					if (j>1 && graph[ID(i,j-1)])
						merge(id,ID(i,j-1));
					if (i>1 && graph[ID(i-1,j)])
						merge(id,ID(i-1,j));
					if (i==1)
						merge(id,0);
				}
			}
		}
		
		tmp=sum[Fa(0)];
		
		for (int Q=q-1,i,j,id,xx,yy; Q>=0; Q--) {
			i=hits[Q][0]+1;
			j=hits[Q][1]+1;
			id=ID(i,j);
			
			if (sum[id]){
				graph[id]=1;
				for (int fx=0; fx<4; fx++) {
					if (OK(xx=i+Fx[fx][0],yy=j+Fx[fx][1]) && graph[ID(xx,yy)]){
						merge(id,ID(xx,yy));
					}
				}
				if (i==1) {
					merge(id,0);
				}
			}
			ret[Q]=sum[Fa(0)]-tmp-(Fa(id)==Fa(0));
			tmp=sum[Fa(0)];
		}
		
		return ret;
    }
};

int main()
{
	vector<vector<int>> grid={{1,0,1},{1,1,1}};
	vector<vector<int>> hits={{0,0},{0,2},{1,1}};
	Solution S;
	vector<int> ans;
	ans=S.hitBricks(grid,hits);
	for (int i=0; i<ans.size(); i++) {
		cout <<ans[i] <<endl;
	}
	return 0;
}
