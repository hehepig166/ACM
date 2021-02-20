#include <bits/stdc++.h>
using namespace std;

#define MaxN 2000005
long long ans[1000005],mn[MaxN],P[MaxN];

void mk_tb(long long *p, long long n)	//打质数表，存到 p 数组 
{
	for (long long i=2; i<=n; ++i) {
		if (!mn[i]) p[mn[i]=++*p]=i;
		for (long long j=1; j<=mn[i] && i*p[j]<=n; ++j) mn[i*p[j]]=j;
	}
}

int main()
{
	mk_tb(P,2000000);
	
	int id=P[0];
	for (int i=1000000; i>2; i--) {
		while (P[id-1]>i)
			id--;
		ans[i]=P[id];
	}
	ans[1]=2;
	ans[2]=3;
	
	long long T,n,a,s;
	scanf("%lld",&T);
	for (int t=1; t<=T; t++) {
		scanf("%lld",&n);
		s=0;
		for (int i=1; i<=n; i++) {
			scanf("%lld",&a);
			s+=ans[a];
		}
		printf("Case %d: %lld Xukha\n",t,s);
	}
	return 0;
}
