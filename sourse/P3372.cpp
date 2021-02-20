#include <cstdio>
#define Mid (l+r>>1)
#define Lx (x<<1)
#define Rx ((x<<1)+1)
int n,m,L,R,d;
long long v[400000],tag[400000],sz[400000],K,ans;

void down_tag(int x){
	v[Lx]+=tag[x]*sz[Lx],v[Rx]+=tag[x]*sz[Rx];
	tag[Lx]+=tag[x],tag[Rx]+=tag[x];
	tag[x]=0;
}

void bui(int x,int l,int r){
	if (l==r){scanf("%lld",&v[x]); sz[x]=1,tag[x]=0; return;}
	bui(Lx,l,Mid);
	bui(Rx,Mid+1,r);
	v[x]=v[Lx]+v[Rx];
	sz[x]=sz[Lx]+sz[Rx];
}

void chg(int x,int l,int r){
	if (L<=l && r<=R){v[x]+=sz[x]*K,tag[x]+=K; return;}
	down_tag(x);
	if (L<=Mid) chg(Lx,l,Mid);
	if (Mid+1<=R) chg(Rx,Mid+1,r);
	v[x]=v[Lx]+v[Rx];
}

long long qry(int x,int l,int r){
	if (L<=l && r<=R) return v[x];
	down_tag(x);
	long long ret=0;
	if (L<=Mid) ret+=qry(Lx,l,Mid);
	if (Mid<R) ret+=qry(Rx,Mid+1,r);
	return ret;
}

int main(){
	freopen("1.txt","r",stdin);
	scanf("%d%d",&n,&m);
	bui(1,1,n);
	while (m--){
		scanf("%d",&d);
		if (d==1){
			scanf("%d%d%lld",&L,&R,&K);
			chg(1,1,n);
			continue;
		}
		scanf("%d%d",&L,&R);
		ans=qry(1,1,n);
		printf("%lld\n",ans);
	}
}
