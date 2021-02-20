#include <bits/stdc++.h>
#define P 998244353
using namespace std;
typedef long long ll;

int n, m, p, q;
ll f[110][110], C[220][220], g[110][110], dp[110][110], h[110];

struct matrix {
	int n, m;  ll _[110][110];
	inline void clear() {n = m = 0;  memset(_,0,sizeof(_));}
	ll* operator[] (int x) {return _[x];}
} a, b;
matrix operator * (matrix A,matrix B) {
	matrix C;  C.clear();  C.n = A.n;  C.m = B.m;
	for (int i=1;i<=A.n;i++) for (int j=1;j<=B.m;j++) for (int k=1;k<=A.m;k++) C[i][j] = (C[i][j] + A[i][k] * B[k][j]) % P;
	return C;
}

int main() {
	freopen("1.txt","r",stdin);
	freopen("std.txt","w",stdout);
	scanf("%d%d%d%d",&n,&m,&p,&q);
		
	for (int i=0;i<=200;i++) {
		C[i][0] = 1;
		for (int j=1;j<=i;j++) C[i][j] = (C[i-1][j] + C[i-1][j-1]) % P;
	}
	
	for (int x=1;x<=p;x++) {
		memset(dp,0,sizeof(dp));
		dp[0][0] = 1;
		for (int i=1;i<=n;i++) {
			for (int y=1;y<=x;y++) dp[i][y] = (dp[i-1][y] * y + dp[i-1][y-1] * (x-y+1)) % P;
		}
		h[x] = dp[n][x];
	}
	
	for (int x=1;x<=p;x++) for (int y=1;y<=p;y++) {
		for (int k=q;k<=p && k <= x+y;k++) {
			b[x][y] = (b[x][y] + C[x][x+y-k] * C[p-x][k-x]) % P;
		}
		b[x][y] = b[x][y] * h[y] % P;
	}
	
	b.n = b.m = a.m = p;  a.n = 1;
	for (int j=1;j<=p;j++) a[1][j] = h[j] * C[p][j] % P;
	
	for (--m;m;m>>=1) {
		if (m & 1) a = a * b;
		b = b * b;
	}
	ll ans = 0;
	for (int j=1;j<=p;j++) (ans += a[1][j]) %= P;
	//printf("%lld\n",ans);
	for (int i=1; i<=p; i++){
		for (int j=1; j<=p; j++) printf("%d\t",dp[i][j]);
		puts("");
	}
}
