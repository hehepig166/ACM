#include <cstdio>

long long n,m,k,l,r,a[200005],b[200005],i,j;

int main()
{
	scanf("%lld%lld",&n,&k);
	m=n<<1;
	for (i=1; i<=n; i++)
		scanf("%lld",&b[i*2+1]);
	
	while (k)
	{
		for (i=1; i<=m; i++)
			a[i]=b[i];
		
		i=0,j=1;
		
		for (; j<=k; j<<=1)
			;
		j>>=1,k-=j;
		l=1-j,r=1+j;
		for (i=1; i<=m; i++)
		{
			l=(l%m+m)%m;
			r=r%m;
			if (!a[l])
				b[i]=0;
			else if (a[l]==a[r])
				b[i]=1;
			else
				b[i]=2;
			l++,r++;
		}
	}
	
	for (i=1; i<=m; i++)
		printf("%lld ",b[i]);
	
	return 0;
}
