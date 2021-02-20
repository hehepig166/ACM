#include <bits/stdc++.h>
using namespace std;
int T;
long long tmp,A,B,n,Sa,Sb,a[100005],b[100005];

bool solve()
{
	scanf("%lld%lld%lld",&A,&B,&n);
	Sa=0;
	Sb=0;
	for (int i=1; i<=n; i++)
		scanf("%lld",&a[i]);
		
	for (int i=1; i<=n; i++)
		scanf("%lld",&b[i]);
	
	for (int i=1; i<=n; i++)
	{
		Sa+=(b[i]/A+(b[i]%A>0))*a[i];
	}
	
	if (Sa<=B)
	{
		return 1;
	}
	
	for (int i=1; i<=n; i++)
	{
		if (Sa-a[i]<B)
		{
			return 1;
		}
	}
	
	return 0;
}

int main()
{
	scanf("%d",&T);
	while (T--)
	{
		puts(solve() ? "YES" : "NO");
	}
	return 0;
}
