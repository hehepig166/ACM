#include <cstdio>
#define abs(x) ((x)<0?(-(x)):x)
#define Ha 998244353

long long a[300],b[300][300],ans,n,L,R;
//b[i][j]:长度为i的区间(如[1,i])选j个数顺序排列(可重复) 

void ha(){
	b[0][0]=1;
	for (int i=0; i<=200; i++)
		for (int j=0; j<=200; j++)
			b[i+1][j+1]=(b[i][j]+b[i+1][j])%Ha;
}

long long he(int l,int r){
	int N=abs(l-r)+1;
	l=a[l],r=a[r];
	if (l==-1) l=0,N++;
	if (r==-1) r=0,N++;
	return b[abs(l-r)][N];
}

int main(){
	ha();
	ans=0;
	scanf("%lld",&n);
	for (int i=1; i<=n; i++) scanf("%lld",&a[i]);
	L=1;
	for (R=2; R<=n; R++){
		if (a[R]==-1) continue;
		ans=(he(L,R)+ans)%Ha;
		L=R+1;
	}
	if (L!=n+1) ans=(he(L,n)+ans)%Ha;
	printf("%lld",ans);
}
