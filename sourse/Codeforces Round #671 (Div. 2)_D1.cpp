#include <cstdio>
#include <algorithm>
using namespace std;
int n,a[100005],b[100005],c[100005];
bool cmp(int x,int y){return a[x]<a[y];}

int main()
{
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
	printf("%d\n",(n-1)/2);
	for (int i=1; i<=n; i++)
		printf("%d ",a[c[i]]);
}
