#include <cstdio>
#define N 1000005
long long f[N][3],n;
int a[N];
char s[N];

long long min(long long x, long long y)
{
	return x>y ? y : x;
}

int main()
{
	
	scanf("%lld",&n);
	scanf("%s",s);
	for (int i=1; i<=n; i++)
		a[i]=s[i-1]-'0';
	
	f[0][0]=N+10;
	f[0][1]=N+10;
	f[0][2]=0;
	
	for (int i=1; i<=n; i++)
	{
		if (a[i]==0)
		{
			f[i][0]=min(f[i-1][0],f[i-1][1]);
			f[i][1]=min(f[i-1][1],f[i-1][2])+1;
			f[i][2]=f[i-1][2];
		}
		if (a[i]==1)
		{
			f[i][0]=min(f[i-1][0],f[i-1][1])+1;
			f[i][1]=min(f[i-1][1],f[i-1][2]);
			f[i][2]=f[i-1][2]+1;
		}
	}
	
	printf("%lld",min(f[n][0],min(f[n][1],f[n][2])));
	return 0;
}

/*
6
010011
*/
