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
//const int N   = ;
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
int T,n,a[100000+233],x;
signed main()
{
	read(T);
	while (T--)
	{
		read(n);read(x);
		int flag=1;
		rep(i,n) read(a[i]);
		rep(i,n) if (a[i]!=x) flag=0;
		if( flag) 
		{
			printf("0\n");
		}
		LL sum=0;
		rep(i,n) sum+=a[i]-x;
		if (sum==0) printf("1\n");
		else printf("2\n");
	}
	return 0;
}

