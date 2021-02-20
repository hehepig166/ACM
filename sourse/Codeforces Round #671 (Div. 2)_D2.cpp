#include <cstdio>
#include <algorithm>
using namespace std;
int n,a[100005],b[100005],c[100005];
bool cmp(int x,int y){return a[x]<a[y];}

int main()
{
	int ans=0;
	scanf("%d",&n);
	for (int i=1; i<=n; i++)
	{
		scanf("%d",&a[i]);
		b[i]=i;
	}
	sort(b+1,b+n+1,cmp);
	for (int i=1,j=n/2; i<=j; i++)
	{
		c[2*i]=b[i];
		c[2*i-1]=b[j+i];
	}
	if (n%2) c[n]=b[n];
	
	for (int i=1; i<=n; i++)
		b[i]=a[c[i]];
	for (int i=2; i<n; i++)
		ans+=(b[i]<b[i-1] && b[i]<b[i+1]);
	
	printf("%d\n",ans);
	for (int i=1; i<=n; i++)
		printf("%d ",a[c[i]]);
}
