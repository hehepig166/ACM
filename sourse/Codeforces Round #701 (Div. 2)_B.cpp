#include <bits/stdc++.h>
using namespace std;

long long n,q,k,ans,l[100005],r[100005],a[100005],f[100005],s[100005];

int main()
{
	scanf("%lld%lld%lld",&n,&q,&k);
	for (int i=1; i<=n; i++)
	{
		scanf("%lld",&a[i]);
	}
	for (int i=1; i<=q; i++)
	{
		scanf("%lld%lld",&l[i],&r[i]);
	}
	
	s[0]=0;
	a[0]=0;
	a[n+1]=k+1;
	for (int i=1; i<=n; i++)
	{
		f[i]=a[i+1]-a[i-1]-2;
		s[i]=s[i-1]+f[i];
	}
	
	for (int i=1; i<=q; i++)
	{
		ans=s[r[i]-1]-s[l[i]];
		ans+=(k-a[r[i]-1]-1+a[l[i]+1]-2);
		printf("%lld\n",ans);
	}
	
	return 0;
}
