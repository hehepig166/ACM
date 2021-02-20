//#include <bits/stdc++.h>
#include <cstdio>
#include <algorithm>
#include <iostream>
#include <cstring>
#include <limits>
#include <map>
#include <vector>
#include <queue>
#define LL long long
#define ft first
#define sd second
#define mp(x,y) make_pair(x,y)
//#define int LL
using namespace std;
const int N   = 1e5+233;
//const int mod = ;
const int INF =numeric_limits<int >::max();
#define For(n) for (int i=1;i<=n;++i)
#define rep(i,n) for (int i=1;i<=n;++i)
#define repp(i,x,y) for (int i=x;i<=y;++i)
void read(int &x)
{
	x=0;
	char ch=getchar();
	int f=1;
	while (!isdigit(ch)) (ch=='-'?f=-1:0),ch=getchar();
	while ( isdigit(ch)) x=x*10+ch-'0',ch=getchar();
	x*=f;
}

void write(int x)
{
	if (x<0) putchar('-'),x=-x;
	if (x>9) write(x/10);
	putchar(x%10+'0');
}


#define maxn 100000

int f[maxn],n,m,mn[maxn],g,p[maxn];

void mk_tb(int * p,int n)//¡ä¨°?¨º¨ºy¡À¨ª ,¡ä?¦Ì?p¨ºy¡Á¨¦ 
{
	for (int i=2;i<=n;++i)
	{
		if (!mn[i]) p[mn[i]=++*p]=i;
		for (int j=1;j<=mn[i]&&p[j]*i<=n;++j) mn[i*p[j]]=j;
	}
}
int x;
int st[N],tp;
signed main()
{
	read(n);
	mk_tb(p,n);
	//rep(i,p[0])
	int i;
	
	for (i=1;i<=p[0]&&1ll*p[i]*p[i]<=n;++i)
	{
		for (int j=p[i];j<=n;j+=p[i]) 
		  f[j]=1;
		
		printf("B %d\n",p[i]);
		fflush(stdout);
		printf("A %d\n",p[i]);
		fflush(stdout);
		read(x);
		if (x==1) 
		{
			st[++tp]=p[i];
		}
	}
	for (int i=n;i>=2;--i) if (!f[i])
	{
		for (int j=i;j<=n;j+=i)
		{
			f[j]=1;
		}
		printf("B %d\n",i);
		fflush(stdout);
		printf("A %d\n",i);
		fflush(stdout);
		read(x);
		if (x==1) 
		{
			st[++tp]=i;
		}
		
	}
	int ans=1;
	rep(i,tp)
	{
		int tmp=1;
		while (tmp<=n)
		{
			tmp*=st[i];
			printf("B %d\n",tmp);
			fflush(stdout);
			printf("A %d\n",tmp);
			fflush(stdout);
			read(x);
			if (x==0) 
			 {
			 	tmp/=st[i];
			 	break;
			 }
		}
		ans*=tmp;
	}
	printf("C %d\n",ans);
	return 0;
}

