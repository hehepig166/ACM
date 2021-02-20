#include <bits/stdc++.h>
using namespace std;

long long check(long long x, long long y)
{
	long long ret=0;
	while (x!=0)
	{
		ret++;
		x/=y;
	}
	return ret;
}

long long solve()
{
	long long a,b;
	scanf("%lld%lld",&a,&b);
	
	long long ans=10000;
	for (int i=(b==1); i<=100; i++)
	{
		ans=min(ans,check(a,b+i)+i);
	}
	return ans;
}



int main()
{
	int T;
	scanf("%d",&T);
	while (T--)
	{
		cout <<solve() <<endl;
	}
	return 0;
}
