#include <cstdio>
long long A[100005],B[100005],a[100005],x,n;

int main(){
	scanf("%lld",&n);
	x=n-1;
	for (int i=1; i<=n; i++) scanf("%lld",&a[i]);
	for (int i=2; i<=n; i++){
		A[i]=-a[i]%n;
		B[i]=(a[i]+A[i])/n-A[i];
	}
	printf("1 1\n%lld\n",-a[1]);
	a[1]=0;
	if (n==1){
		printf("1 1\n0\n1 1\n0");
		return 0;
	}
	printf("2 %lld\n",n);
	for (int i=2; i<=n; i++) printf("%lld ",-A[i]*x),a[i]-=A[i]*x;
	printf("\n1 %lld\n",n);
	for (int i=1; i<=n; i++) printf("%lld ",-a[i]);
}
