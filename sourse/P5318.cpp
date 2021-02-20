#include <cstdio>
#include <algorithm>
#include <cstring>
#define Add(x,y) cnt++,nxt[cnt]=head[x],head[x]=cnt
#define For(x) for(int h=head[x],V=E[h].v; h; V=E[h=nxt[h]].v)
using namespace std;
int n,m,f[1000005];
int nxt[3000000],head[1000005],cnt;

struct edge{
	int u,v;
} E[3000000];

bool cmp(edge x,edge y){
	return x.v>y.v;
}


void dfs(int x){
	printf("%d ",x);
	f[x]=1;
	For(x) if (!f[V]) dfs(V);
}

struct que{
	int l,r,a[3000000];
	void Reset(){
		l=1;
		r=0;
		memset(a,0,sizeof(a));
	}
	void Ins(int x){
		r++;
		a[r]=x;
	}
	int Pop(){
		if (l>r) return -1;
		l++;
		return a[l-1];
	}
	bool Empty(){
		return l>r;
	}
} Q;

void bfs(int x){
	Q.Reset();
	Q.Ins(1);
	f[x]=1;
	while (!Q.Empty()){
		x=Q.Pop();
		printf("%d ",x);
		For(x) if (!f[V]){
			Q.Ins(V);
			f[V]=1;
		}
	}
}

int main(){
	scanf("%d%d",&n,&m);
	for (int i=1; i<=m; i++){
		scanf("%d%d",&E[i].u,&E[i].v);
	}
	sort(E+1,E+m+1,cmp);
	for (int i=1; i<=m; i++) Add(E[i].u,E[i].v);
	
	memset(f,0,sizeof(f));
	dfs(1);
	printf("\n");
	memset(f,0,sizeof(f));
	bfs(1);
}
