#include <cstdio>
#include <algorithm>
using namespace std;
long long n,m,a[100005],ans,cnt;

int main()
{
	scanf("%lld%lld",&n,&m);
	for (int i=1; i<=m; i++)
		scanf("%lld",&a[i]);
	sort(a+1,a+m+1);
	
	cnt=ans=0;
	for (int i=1; i<=m; i++)
	{
		if (cnt>=n)
		{
			printf("-1");
			return 0;
		}
		else if (a[i]>cnt)
		{
			cnt=a[i];
			continue;
		}
		else
		{
			ans+=(cnt+1-a[i]);
			cnt++;
			continue;
		}
	}
	
	printf("%lld",ans);
	return 0;
}
