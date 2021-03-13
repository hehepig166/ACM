#include <bits/stdc++.h>
using namespace std;

bool check(long long x, long long y)
{
	
	static bool X[32],Y[32];
	for (long long I=1,i=0; i<30; i++,(I<<=1))
	{
		X[i]=x&I;
		Y[i]=y&I;
	}
	
	int c1=0,c2=0;
	
	for (int i=0; i<30; i++)
	{
		c1+=X[i];
		c2+=Y[i];
		if (Y[i] && c1<c2)
			return false;
	}
	
	for (c1=0; c1<30 && X[c1]==0; c1++);
	for (c2=0; c2<30 && Y[c2]==0; c2++);
	
	if (c1>c2)
		return false;
	
	return true;
}

void solve()
{
	int q;
	scanf("%d",&q);
	for (long long i=1,uu,vv; i<=q; i++)
	{
		scanf("%lld%lld",&uu,&vv);
		if (vv<uu)
		{
			puts("NO");
			continue;
		}
		if (vv==uu)
		{
			puts("YES");
			continue;
		}
		
		puts(check(uu,vv) ? "YES" : "NO");
	}
}

int main()
{
	solve();
	return 0;
}
