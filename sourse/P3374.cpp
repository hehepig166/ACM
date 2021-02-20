#include <cstdio>
#define lowbit(x) (x&(-x))
int n,m,d,p,q;
long long k,c[500005];

void Add(int x,long long y){
	for (; x<=n; x+=lowbit(x)) c[x]+=y;
}
long long qry(int x){
	long long ret=0;
	for (; x>0; x-=lowbit(x)) ret+=c[x];
	return ret;
}

int main(){
	scanf("%d%d",&n,&m);
	for (int i=1; i<=n; i++){
		scanf("%lld",&k);
		Add(i,k);
	}
	while (m--){
		scanf("%d",&d);
		if (d==1){
			scanf("%d%lld",&p,&k);
			Add(p,k);
			continue;
		}
		scanf("%d%d",&p,&q);
		printf("%lld\n",qry(q)-qry(p-1));
	}
}
