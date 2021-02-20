#include <cstdio>
#include <algorithm>
using namespace std;
int T,n,k,cnt,a[200],ans;

int main()
{
	scanf("%d",&T);
	while (T--)
	{
		cnt=0;
		scanf("%d%d",&n,&k);
		for (int i=1; i<=n; i++) scanf("%d",&a[i]);
		sort(a+1,a+n+1);
		a[0]=-1;
		for (int i=1; i<=n; i++) cnt+=a[i]!=a[i-1];
		
		if (k==1)
		{
			cnt==1 ? printf("1\n") : printf("-1\n");
			continue;
		}
		
		ans=0;
		if (k>=cnt)
		{
			printf("1\n");
			continue;
		}
		ans=1+(cnt-k-1)/(k-1)+1;
		printf("%d\n",ans);
	}
}
