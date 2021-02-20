#include <cstdio>
typedef long long LL;
LL n,k,Sum,mt,tmp,a[1000005];

int main()
{
	scanf("%lld%lld",&n,&k);
	for (int i=1; i<n; i++){
		scanf("%lld",&a[i]);
		Sum+=a[i];
		
	}
	
	
	if (n>k){
		tmp=mt=0;
		for (int i=1; i<=k; i++)
			tmp+=a[i];
		mt=tmp;
		for (int i=k+1; i<n; i++){
			tmp+=a[i]-a[i-k];
			if (tmp>mt)
				mt=tmp;
		}
		Sum-=mt;
	}
	
	printf("%lld",Sum);
	
	return 0;
}
