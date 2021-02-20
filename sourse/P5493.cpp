#include <cstdio>
#include <cstring>
using namespace std;
const long long INF=40000000000;
const long long SQR=300000;
long long n,k,Ha;
long long p[SQR+5],f[SQR+5],num;
long long g1[SQR],g2[SQR];

void get_p()
{
	num=0;
	memset(f,0,sizeof(f));
	for (long long x=2; x*x<=INF; x++)
	{
		if (!f[x])
			p[++num]=x;
		for (long long i=1; i<=num && x*p[i]<=SQR; i++)
			f[x*p[i]]=1;
	}
}

void get_g(long long N)
{
	for (int i=)
}

int main()
{
	get_p();
	scanf("%lld%lld%lld",&n,&k,&Ha);
	get_g();
	return 0;
}
