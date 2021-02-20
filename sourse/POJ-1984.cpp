#include <cstdio>
#include <iostream>
#include <algorithm>
#define N 40005
using namespace std;
long long n,m,aa[N],bb[N],ll[N];
long long c[10005],cnt,k,q[10005][3];
long long a,b,l,fa,fb;
long long fx[N],fy[N],vx[N],vy[N];
char s,ss[N][2];

bool cmp(int x, int y)
{
	return q[x][2]<q[y][2];
}

long long Fa(long long x, long long f[], long long v[])
{
	if (f[x]==x)
	{
		return x;
	}
	long long tmp=f[x];
	f[x]=Fa(tmp,f,v);
	v[x]+=v[tmp];
	return f[x];
}

void solve(long long A, long long B)
{
	long long fxA,fxB,fyA,fyB;
	fxA=Fa(A,fx,vx);
	fxB=Fa(B,fx,vx);
	fyA=Fa(A,fy,vy);
	fyB=Fa(B,fy,vy);
	if (fxA!=fxB || fyA!=fyB)
	{
		puts("-1");
		return;
	}
	printf("%lld\n",abs(vx[A]-vx[B])+abs(vy[A]-vy[B]));
}

int main()
{
	while (scanf("%lld%lld",&n,&m)==2)
	{
		
		for (long long i=1; i<=m; i++)
		{
			scanf("%lld%lld%lld%s",&aa[i],&bb[i],&ll[i],ss[i]);
			if (ss[i][0]=='S' || ss[i][0]=='W')
			{
				ll[i]=-ll[i];
			}
		}
		scanf("%lld",&k);
		for (long long i=1; i<=k; i++)
		{
			scanf("%lld%lld%lld",&q[i][0],&q[i][1],&q[i][2]);
			c[i]=i;
		}
		sort(c+1,c+k+1,cmp);
		
		// init
		for (int i=1; i<=n; i++)
		{
			fx[i]=fy[i]=i;
			vx[i]=vy[i]=0;
		}
		
		cnt=1;
		for (long long i=1; i<=m; i++)
		{
			a=aa[i],b=bb[i],l=ll[i],s=ss[i][0];
			if (s=='E' || s=='W')
			{
				fa=Fa(a,fx,vx);
				fb=Fa(b,fx,vx);
				if (fa!=fb)
				{
					vx[fa]=l-vx[a]+vx[b];
					fx[fa]=fb;
				}
				
				fa=Fa(a,fy,vy);
				fb=Fa(b,fy,vy);
				if (fa!=fb)
				{
					vy[fa]=vy[b]-vy[a];
					fy[fa]=fb;
				}
			}
			else
			{
				fa=Fa(a,fy,vy);
				fb=Fa(b,fy,vy);
				if (fa!=fb)
				{
					vy[fa]=l-vy[a]+vy[b];
					fy[fa]=fb;
				}
				
				fa=Fa(a,fx,vx);
				fb=Fa(b,fx,vx);
				if (fa!=fb)
				{
					vx[fa]=vx[b]-vx[a];
					fx[fa]=fb;
				}
			}
			
			while (cnt<=k && q[cnt][2]==i)
			{
				solve(q[cnt][0],q[cnt][1]);
				cnt++;				
			}
			
			if (cnt>k)
			{
				break;
			}
		}
	}
	return 0;
}
