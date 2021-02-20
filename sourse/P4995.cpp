#include <cstdio>
#include <algorithm>
#define HA(x,y) (h[i]-h[j])*(h[i]-h[j])
using namespace std;
int n,h[305];
long long ans=0;

int main()
{
	scanf("%d",&n);
	for (int i=1; i<=n; i++)
		scanf("%d",&h[i]);
	sort(h,h+n+1);
	for (int i=0,j=n; i<j; )
	{
		ans+=HA(i,j);
		i++;
		if (i<=j)
		{
			ans+=HA(j,i);
			j--;
		}
	}
	printf("%lld",ans);
	return 0;
}
