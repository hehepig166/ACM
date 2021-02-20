#include <cstdio>
long long n,p,a[100005],b[100005];
double ans,Sa;

int check(double t)
{
	double S=0;
	for (int i=1; i<=n; i++)
		if (t*a[i]>=b[i])
			S+=t*a[i]-b[i];
	
	return S<=t*p;
}

int main()
{
	scanf("%lld%lld",&n,&p);
	for (int i=1; i<=n; i++)
		scanf("%lld%lld",&a[i],&b[i]);
	
	Sa=0;
	for (int i=1; i<=n; i++)
		Sa+=a[i];
	
	if (Sa<=p){
		printf("-1");
		return 0;
	}
	
	ans=0;
	for (double l=0,r=1e10,mid; (r-l)>=1e-6; ){
		mid=(l+r)/2;
		if (check(mid)){
			l=mid;
			ans=mid;
		}
		else
			r=mid;
	}
	
	printf("%.5lf",ans);
	return 0;
}
