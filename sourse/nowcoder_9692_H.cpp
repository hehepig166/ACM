#include <cstdio>
#define N 100005
long long n,m,a[N],ans;

long long check(long long x)
{
	long long ret=0,d1,d2;
	for (int i=2; i<=n; i++)
	{
		d1=((a[i]-a[i-1])+m)%m;
		d2=(a[i]-x+m)%m+1;
		ret+= (d1<d2) ? d1 : d2 ;
	}
	return ret;
}

long long Solve(long long L,long long R)
{
	long long len,mid1,mid2,s1,s2,ret;
	while (L<R)
	{
		len=(R-L)/3,mid1,mid2,s1,s2;
		mid1=L+len;
		mid2=R-len;
		
		s1=check(mid1);
		s2=check(mid2);
		
		if (s1<s2)
		{
			ret=s1;
			R=mid2-1;
		}
		else
		{
			ret=s2;
			L=mid1+1;
		}
	}
	
	return ret;
}

int main()
{
	scanf("%lld%lld",&n,&m);
	for (int i=1; i<=n; i++)
	{
		scanf("%lld",&a[i]);
		a[i]--;
	}
	
	ans=Solve(0,m-1);
	
	printf("%lld",ans);
	return 0;
}

/*
4 6
1 5 1 4
*/
