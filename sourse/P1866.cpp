#include <cstdio>
#include <algorithm>
#define Ha 1000000007
using namespace std;
int n,a[100],tmp;
long long ans;



int main()
{

	scanf("%d",&n);
	for (int i=1; i<=n; i++)
		scanf("%d",&a[i]);
	sort(a+1,a+n+1);
	
	ans=1;
	for (int i=1; i<=n; i++){
		tmp=a[i]-i+1;
		if (tmp>=1){
			ans=ans*tmp%Ha;
			continue;
		}
		else{
			puts("0");
			return 0;
		}
	}
	
	printf("%lld\n",ans);
	
	return 0;
}
