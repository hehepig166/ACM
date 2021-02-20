#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
int n,tmp,tmp1,L,R,M,a[100005];

bool check(int X)
{
	if (!a[X])
	{
		printf("? %d\n",X);
		fflush(stdout);
		scanf("%d",&a[X]);
	}
	if (a[1]-a[X] < X-1)
	{
		return 0;
	}
	if (a[X]==1)
	{
		return 1;
	}
	if (!a[X-1])
	{
		printf("? %d\n",X-1);
		fflush(stdout);
		scanf("%d",&a[X-1]);
	}
	else
	{
		
	}
	return a[X-1]>a[X];
}

int main()
{
	scanf("%d",&n);
	
	puts("? 1");
	fflush(stdout);
	scanf("%d",&a[1]);
	L=1,R=n;
	while (L<R)
	{
		M=(L+R+1)>>1;
		if (check(M))
		{
			L=M;
		}
		else
		{
			R=M-1;
		}
	}
	printf("! %d\n",L);
	
	return 0;
}
