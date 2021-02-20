#include <bits/stdc++.h>
using namespace std;

void solve()
{
	long long ans=0,X,Y,l,r;
	scanf("%lld%lld",&X,&Y);
	
	
	Y++;
	l=1,r=X;
	while (r>2)
	{
		//ans+=(min(Y,l)-1)+min(Y,r)-1;
		if (r>2)
			ans+=max(min(Y,r)-(l+1),0ll);
		r=X/(l+1);
		l=X/(r);
	}
	
	
	/*
	for (long long a=1; a<=X; a++)
	{
		for (long long b=1; b<=Y; b++)
		{
			if (a/b==a%b)
			{
				ans++;
				printf("%lld %lld %lld\n",a,b,a%b);
			}
		}
	}
	*/
	
	printf("%lld\n",ans);
}



int main()
{
	int T;
	scanf("%d",&T);
	while (T--)
	{
		solve();
	}
	return 0;
}
