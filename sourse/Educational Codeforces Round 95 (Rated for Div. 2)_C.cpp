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
const int N   = 2e5+233;
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

void upd(int &x,int y)
{
	x=min(x,y);
}
int T,n,a[N],f[N][2];
signed main()
{
	read(T);
	while (T--)
	{
		read(n);
		rep(i,n) read(a[i]),f[i][0]=f[i][1]=n;
		f[1][0]=a[1];
		f[2][0]=a[1]+a[2];
		rep(i,n) 
		{
			upd(f[i+1][1],f[i][0]);
			upd(f[i+2][1],f[i][0]);
			upd(f[i+1][0],f[i][1]+a[i+1]);
			upd(f[i+2][0],f[i][1]+a[i+1]+a[i+2]);
		}
		printf("%d\n",min(f[n][0],f[n][1]));
	}
	return 0;
}

/*
1
6
1 1 1 1 1 1
*/

