#include <cstdio>
#include <algorithm>
using namespace std;
int n,t,m[200],v[200],c[200];
double ans,w[200];

bool cmp(int x,int y){
	return w[x]>w[y];
}

int main(){
	ans=0;
	scanf("%d%d",&n,&t);
	for (int i=1; i<=n; i++){
		scanf("%d%d",&m[i],&v[i]);
		w[i]=(double)v[i]/m[i];
		c[i]=i;
	}
	sort(c+1,c+n+1,cmp);
	for (int i=1; i<=n && t; i++){
		if (t>m[c[i]]) ans+=v[c[i]],t-=m[c[i]];
		else ans+=w[c[i]]*t,t=0;
	}
	printf("%.2lf",ans);
}
