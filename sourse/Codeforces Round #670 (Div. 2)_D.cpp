#include <cstdio>
#define M ((l+r)>>1)
#define lowbit(x) (x&(-x))
long long n,L,R,X,q,sb,sc,ll,rr,a[100005];
long long ans;

int check(long long x){
	if ((ll-x+sb)>x) return 0;
	return 1;
}

void ef(long long l,long long r){
	if (l==r){
		ans=l;
		return;
	}
	if (check(M)){
		ef(l,M);
		return;
	}
	ef(M+1,r);
}

int main(){
	scanf("%lld",&n);
	for (int i=1; i<=n; i++) scanf("%lld",&a[i]);
	for (int i=1; i<n; i++){
		if (a[i+1]>a[i]) sb+=a[i+1]-a[i];
		else sc+=a[i+1]-a[i];
	}
	ll=a[1],rr=a[n];
	for (int i=1; i<n; i++) a[i]=a[i+1]-a[i];
	//for (int i=1; i<=n; i++) S.Add(i,i,a[i]);
	ef(-10000000000000000ll,10000000000000000ll);
	printf("%lld\n",ans);
	
	scanf("%lld",&q);
	while (q--){
		scanf("%lld%lld%lld",&L,&R,&X);
		if (L==1) ll+=X;
		
		if ((L-1)>0) (a[L-1]>0) ? sb-=a[L-1] : sc-=a[L-1];
		if (R<n) (a[R]>0) ? sb-=a[R] : sc-=a[R];
		
		if (L-1>0) a[L-1]+=X;
		if (R<n) a[R]-=X;
		
		if ((L-1)>0) (a[L-1]>0) ? sb+=a[L-1] : sc+=a[L-1];
		if (R<n) (a[R]>0) ? sb+=a[R] : sc+=a[R];
		
		ef(-10000000000000000ll,10000000000000000ll);
		printf("%lld\n",ans);
	}
}

/*
4
-3 6 -2 -8 
3
1 3 -4
3 3 5
3 3 -4

*/
