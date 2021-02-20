#include <cstdio>
#include <cstring>
#define Ha 998244353
#define Max 1000000
typedef long long LL;
using namespace std;

LL N,M,c[Max+5],f[Max+5],a[Max+5],b[Max+5],ans,ss;
LL jc[1000005];

LL ksm(LL x,LL n)
{
	LL ret=1;
	for (LL i=1,tmp=x; n; ) {
		if (n&i) {
			ret=ret*tmp%Ha;
			n^=i;
		}
		tmp=tmp*tmp%Ha;
		i<<=1;
	}
	return ret;
}

LL C(LL x,LL y)
{
	LL ret=jc[x];
	ret=ret*ksm(jc[y],Ha-2)%Ha;
	ret=ret*ksm(jc[x-y],Ha-2)%Ha;
	return ret;
}

int main()
{
	
	jc[0]=jc[1]=1;
	for (LL i=2; i<=1000000; i++) jc[i]=jc[i-1]*i%Ha;

	scanf("%lld%lld",&N,&M);
	for (LL i=1; i<=N; i++){
		scanf("%lld",&a[i]);
		c[a[i]]++;
	}
	
	f[1]=ksm(2,c[1]);
	for (LL i=2,cc,nn=N; i<=Max && nn; i++){	//元素是 i 的 
		for (LL k=i,tmp=1; k<=M && tmp<=c[i]; k=k*i,tmp++){		//选 tmp 个 i 
			cc=C(c[i],tmp);		//组合数 
			for (LL j=M/k; j; j--){
				b[j*k]=(b[j*k]+f[j]*cc)%Ha;		//dp 
			}
		}
		for (LL j=M/i; j; j--){	//清空临时改变量数组 
			f[j*i]=(f[j*i]+b[j*i])%Ha;
			b[j*i]=0;
		}
		nn-=c[i];
	}
	
	for (LL i=1; i<=M; i++)
		ss=(ss+f[i])%Ha;
	
	ans=ksm(2,N);
	ans-=ss;
	ans=(ans%Ha+Ha)%Ha;
	
	printf("%lld",ans);
	return 0;
}
/*
5 5
1 2 1 2 2
*/
