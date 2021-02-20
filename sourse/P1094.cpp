#include <cstdio>
#include <algorithm>
#define I b[i]
#define J b[j]
using namespace std;
int w,n,ans=0,a[40000],b[40000];
bool cmp(int x,int y){return a[x]<a[y];}

int main()
{
	scanf("%d%d",&w,&n);
	for (int i=b[1]=1; i<=n; b[i]=++i)
		scanf("%d",&a[i]);
	sort(b+1,b+n+1,cmp);
	for (int i=n,j=1; i>=j; )
	{
		if (i==j)
		{
			ans++;
			printf("%d",ans);
			return 0;
		}
		if (a[I]+a[J]<=w)
		{
			ans++;
			i--;
			j++;
			continue;
		}
		ans++;
		i--;
	}
	printf("%d",ans);
	return 0;
}
