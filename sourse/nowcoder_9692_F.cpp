#include <cstdio>
#define Ha (1000000007)
long long f[3000],h[3000],c[3000][3000],N;

void get_C()
{
	c[0][0]=1;
	for (int i=1; i<=2000; i++)
	{
		c[i][0]=c[i][i]=1;
		for (int j=1; j<i; j++)
			c[i][j]=(c[i-1][j-1]+c[i-1][j])%Ha;
	}
}

void get_h(long long x)
{
	int L,R;
	h[1]=h[2]=1;
	for (int n=3; n<=x; n++)
	{
		for (int i=1; i<n; i++)
		{
			
			L=i,R=n-i;
			h[n]=(h[n]  +  c[R+L-2][L-1]*h[L]%Ha*h[R]%Ha)%Ha;
		}
	}
	
}

void Solve(long long n)
{
	if (f[n] || n<=2)
		return;
	
	for (int i=1; i<n; i++)
	{
		int L=i,R=n-i;
		
		Solve(i);
		Solve(n-i);

		f[n]=(f[n]+ ( f[L]*h[R]  +  f[R]*h[L] )%Ha*c[R+L-2][L-1]%Ha )%Ha;
	}
	
	f[n]=(f[n]+h[n]*n)%Ha;
	return;
}

int main()
{
	get_C();
	scanf("%lld",&N);
	
	f[1]=0;
	f[2]=2;
	
	
	get_h(N);
	Solve(N);
	
	printf("%lld",f[N]);
	return 0;
}
