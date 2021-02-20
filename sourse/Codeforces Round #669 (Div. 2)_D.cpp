#include <cstdio>
#define Add(x,y) nxt[0][++cnt]=(y),nxt[1][cnt]=A[x],A[x]=cnt
#define For(x) for(int kk=A[x],v=nxt[0][kk]; kk; kk=nxt[1][kk],v=nxt[0][kk])
int n,a[500000],dp[500000];
int st[500000],top;
int A[500000],nxt[2][20000000],cnt;

int main(){
	scanf("%d",&n);
	for (int i=1; i<=n; i++) scanf("%d", &a[i]);
	
	top=0;
	st[0]=0;
	for (int i=1; i<=n; i++){
		while (a[st[top]]<a[i] && top) top--;
		if (top) Add(i,st[top]);
		st[++top]=i;
	}
	
	top=0;
	st[0]=0;
	for (int i=1; i<=n; i++){
		while (a[st[top]]>a[i] && top) top--;
		if (top) Add(i,st[top]);
		st[++top]=i;
	}
	
	top=0;
	st[0]=0;
	for (int i=n; i; i--){
		while (a[st[top]]<a[i] && top) top--;
		if (top) Add(st[top],i);
		st[++top]=i;
	}
	
	top=0;
	st[0]=0;
	for (int i=n; i; i--){
		while (a[st[top]]>a[i] && top) top--;
		if (top) Add(st[top],i);
		st[++top]=i;
	}
	
	/*
	for (int i=2; i<=n; i++){
		printf("[%d]\t",i);
		For(i) printf("%d ",v);
		printf("\n");
	}
	*/
	
	
	//dp[i]: 走到 i 最少步数
	for (int i=1; i<=n; i++) dp[i]=2147483647;
	dp[1]=0;
	for (int i=2; i<=n; i++){
		For(i) if (v){
			if (dp[v]+1<dp[i]) dp[i]=dp[v]+1;
		}
	}
	printf("%d",dp[n]);
}
