#include <cstdio>
#define Add(x,y) cnt++,nxt[0][cnt]=head[x],nxt[1][cnt]=y,head[x]=cnt
#define For(x) for(int h=head[x],vv=nxt[1][h]; h; vv=nxt[1][h=nxt[0][h]])
int head[100005],nxt[2][200005],cnt;
int n,m,a[100005],f[100005];

void he(int x){
	f[x]=1;
	For(x) if (!f[vv]){
			a[vv]=a[x];
			he(vv);
	}
}

int main(){
	scanf("%d%d",&n,&m);
	for (int i=1,u,v; i<=m; i++){
		scanf("%d%d",&u,&v);
		Add(v,u);
	}
	for (int i=1; i<=n; i++) a[i]=i,f[i]=0;
	for (int i=n; i; i--){
		if (!f[i]) he(i);
	}
	for (int i=1; i<=n; i++) printf("%d ",a[i]);
}
