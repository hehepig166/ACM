#include <cstdio>
#include <algorithm>
using namespace std;
int n,m,k,cnt,s[1000005],a[1000005];
long long sum,ans=0,s1[1000005],s2[1000005];

int main(){
	scanf("%d%d%d",&n,&m,&k);
	s1[0]=s2[0]=0;
	for (int i=1; i<=n; i++) scanf("%d",&s[i]);
	for (int i=1; i<=m; i++) scanf("%d",&a[i]);
	for (int i=1; i<=n; i++) s1[i]=s1[i-1]+s[i];
	sort(a+1,a+1+m);
	for (int i=1; i<=m; i++) s2[i]=s2[i-1]+a[i];
	cnt=0;
	for (int i=n; i; i--){
		while (a[cnt+1]<=s[i] && cnt<m) cnt++;
		sum=s2[cnt];
		if (cnt>k) sum-=s2[cnt-k];
		if (ans<s1[i]+sum) ans=s1[i]+sum;
	}
	printf("%lld",ans);
}
