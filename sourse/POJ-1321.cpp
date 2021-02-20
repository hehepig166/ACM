#include <cstdio>
int r[10]={0},c[10]={0},n,k;
int cnt;
char a[10][10]={0};

void dfs(int dep,int X,int Y)
{
	if (dep>=k){
		cnt++;
		return;
	}
	
	if (X>=n)
		return;
	
	int x=X+(Y+1)/n,y=(Y+1)%n;
	
	dfs(dep,x,y);
	
	if (!r[X] && !c[Y] && a[X][Y]=='#'){
		r[X]=c[Y]=1;
		
		dfs(dep+1,x,y);
		
		r[X]=c[Y]=0;
	}
	
}

int main()
{
	while (1){
		scanf("%d%d",&n,&k);
		if (n==-1)
			break;
		
		for (int i=0; i<n; i++)
			scanf("%s",a[i]);
		
		cnt=0;
	
		dfs(0,0,0);
		
		printf("%d\n",cnt);
	}
	return 0;
}
