#include <cstdio>
#define For(x) for(int h=head[x],o=V[h]; h; o=V[h=nxt[h]])
int head[100005],nxt[200005],V[200005],cnt;
int s[100005],A[100005],B[100005];
char a[100005],C[100005];
int N,M;

inline void Add(int u,int v)
{
	cnt++;
	V[cnt]=v;
	nxt[cnt]=head[u];
	head[u]=cnt;
}

void dfs(int x,int fa,int sH,int sG)
{
	if (a[x]=='H'){
		if (a[x]==a[fa]){
			s[x]=sH;
		}
		else{
			s[x]=x;
			sH=x;
		}
	}
	else{
		if (a[x]==a[fa]){
			s[x]=sG;
		}
		else{
			s[x]=x;
			sG=x;
		}
	}
	
	For(x) if (o!=fa) 
		dfs(o,x,sH,sG);
}

int main()
{
	//freopen("1.txt","r",stdin);
	//freopen("1.out","w",stdout);
	scanf("%d%d",&N,&M);
	scanf("%s",a+1);
	for (int i=1,xx,yy; i<N; i++) {
		scanf("%d%d",&xx,&yy);
		Add(xx,yy);
		Add(yy,xx);
	}
	for (int i=1,xx,yy; i<=M; i++) {
		scanf("%d%d %c",&A[i],&B[i],&C[i]);
	}
	
	dfs(1,0,0,0);
	
	for (int i=1; i<=M; i++) {
		if (C[i]=='H'){
			printf("%d",!(a[A[i]]!='H' && a[B[i]]!='H' && s[A[i]]==s[B[i]]));
		}
		else{
			printf("%d",!(a[A[i]]!='G' && a[B[i]]!='G' && s[A[i]]==s[B[i]]));
		}
	}
	
	return 0;
}
