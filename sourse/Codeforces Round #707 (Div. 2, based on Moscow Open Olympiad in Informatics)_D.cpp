#include <bits/stdc++.h>
using namespace std;

long long n,m,k,nmgcd,nmlcm;

long long gcd(long long x, long long y){return y ? gcd(y,x%y) : x;}
long long lcm(long long x, long long y)
{
	long long tt=gcd(x,y);
	tt=x*y/tt;
	return tt;
}

long long exgcd(long long aa,long long bb,long long &x,long long &y)//扩展欧几里得算法
{
    if(bb==0)
    {
        x=1;y=0;
        return aa;  //到达递归边界开始向上一层返回
    }
    long long r=exgcd(bb,aa%bb,x,y);
    long long temp=y;    //把x y变成上一层的
    y=x-(aa/bb)*y;
    x=temp;
    return r;     //得到a b的最大公因数
}

#define N 500005

long long a[N],b[N],fa[N<<1],fb[N<<1],s[N<<1],MM;

bool check(long long x)
{
	long long cnt=x;
	for (long long i=MM; i; i--) if (s[i]>0)
	{
		if (x>=s[i])
		{
			cnt-=(x-s[i])/nmlcm+1;
		}
	}
	return cnt>=k;
}

void solve()
{
	scanf("%lld%lld%lld",&n,&m,&k);
	MM=max(n,m)<<1;
	
	
	
	for (long long i=1; i<=n; i++)
	{
		scanf("%lld",&a[i]);
		fa[a[i]]=i;
	}
	
	for (long long i=1; i<=m; i++)
	{
		scanf("%lld",&b[i]);
		fb[b[i]]=i;
	}
	
	nmgcd=gcd(n,m);
	nmlcm=lcm(n,m);
	
	for (long long colr=MM; colr; colr--)
	{		
		if (fa[colr]==0 || fb[colr]==0 || (fb[colr]-fa[colr])%nmgcd!=0)
		{
			s[colr]=-1;
			continue;
		}
		
		if (fa[colr]==fb[colr])
		{
			s[colr]=fa[colr];
			continue;
		}
		
		long long x1,x2,tmp;
		exgcd(n,m,x1,x2);
		x1*=((fb[colr]-fa[colr])/nmgcd);
		x2*=((fb[colr]-fa[colr])/nmgcd);
		tmp=x1*n+fa[colr];
		tmp=((tmp-1)%nmlcm+nmlcm)%nmlcm+1;
		s[colr]=tmp;
	}
	
	long long L=1,R=(1ll<<61),M,ans;
	for (; L<R; )
	{
		M=(L+R)>>1;
		if (check(M))
			ans=R=M;
		else
			L=M+1;
	}
	
	printf("%lld\n",ans);
}

int main()
{
	solve();
	return 0;
}

/*
3 8 41
1 3 2
1 6 4 3 5 7 2 8
*/
