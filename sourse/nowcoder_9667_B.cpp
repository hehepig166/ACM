#include <cstdio>
#include <algorithm>
using namespace std;

bool cmp(int x,int y)
{
	return a[x]<a[y];
}

int main()
{
	scanf("%d",&n);
	for (int i=1; i<=n; i++)
	{
		scanf("%d",&a[i]);
		c[i]=i;
	}
	
	sort(c+1,c+n+1,cmp);
	
	for (int i=1; i<=n; i++)
	{
		f[i]=0;
		ans+=
	}
	return 0;
}
