#include <cstdio>
int T,n,a[200],b[200],c[200],d[200];

int main()
{
	scanf("%d",&T);
	while (T--)
	{
		scanf("%d",&n);
		for (int i=1; i<=n; i++) scanf("%d",&a[i]);
		for (int i=1; i<=n; i++) scanf("%d",&b[i]);
		for (int i=1; i<=n; i++) scanf("%d",&c[i]);
		d[1]=a[1];
		for (int i=2; i<=n; i++)
		{
			if (d[i-1]!=a[i]) d[i]=a[i];
			if (d[i-1]!=b[i]) d[i]=b[i];
			if (d[i-1]!=c[i]) d[i]=c[i];
		}
		if (d[n]==d[1])
		{
			if (a[n]!=d[1] && a[n]!=d[n-1]) d[n]=a[n];
			if (b[n]!=d[1] && b[n]!=d[n-1]) d[n]=b[n];
			if (c[n]!=d[1] && c[n]!=d[n-1]) c[n]=b[n];
		}
		for (int i=1; i<=n; i++) printf("%d ",d[i]);
		printf("\n");
	}
}
