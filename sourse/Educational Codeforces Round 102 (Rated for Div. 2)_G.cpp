#include <cstdio>
#define N 1005
#define Ha 998244353
typedef long long LL;
int n,h,a[N],b[N];
LL jc[10005];	//阶乘 
LL ans[N][N<<3];

//快速幂 
LL ksm(LL x, LL t) {
	LL ret=1;
	for (; t; (t>>=1),(x=x*x%Ha)) {
		if (t&1) {
			ret=ret*x%Ha;
		}
	}
	return ret;
}

//组合数 
LL C(LL x, LL y) {
	
	if (y>x || y<0) {
		return 0;
	}
	
	if (x-y>y) {
		y=x-y;
	}
	
	LL ret;
	ret=jc[x];
	ret=ret*ksm(jc[y],Ha-2)%Ha;
	ret=ret*ksm(jc[x-y],Ha-2)%Ha;
	return ret;
}


int main() {
	
	
	jc[0]=jc[1]=1;
	for (int i=2; i<=10000; i++) {
		jc[i]=(jc[i-1]*i)%Ha;
	}
	
	scanf("%d",&n);
	for (int i=1; i<=n; i++) {
		scanf("%d%d",&a[i],&b[i]);
	}
	
	ans[0][1]=1;
	h=1;
	for (int i=1; i<=n; i++) {
		for (int j=1,mj=h+a[i]-b[i]; j<=mj; j++) {
			LL tmp=0;
			for (int k=1; k<=h; k++) {
				tmp+=ans[i-1][k]*C(a[i]+b[i],j-k+b[i])%Ha;
				tmp%=Ha;
			}
			ans[i][j]+=tmp;
			ans[i][j]%=Ha;
		}
		h+=a[i]-b[i];
	}
	
	LL Ans=0;
	for (int i=1; i<=h; i++) {
		Ans+=ans[n][i];
		Ans%=Ha;
	}
	
	printf("%lld\n",Ans);
	
	return 0;
}

/*
2
4 2
2 3

*/
