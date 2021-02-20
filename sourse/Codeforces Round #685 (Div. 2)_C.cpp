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
const int N   = 1e6+233;
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
int n,k,x[50],y[50];
char a[N],b[N];
int solve()
{
	//int ;
	for (int i=0;i<=26;++i) x[i]=y[i]=0;
	rep(i,n) x[a[i]-'a']++,y[b[i]-'a']++;
	for (int i=0;i<26;++i)
	  if (x[i]<y[i]||(x[i]-y[i])%k!=0) return 0;
	  else 
	  {
	  	x[i+1]+=x[i]-y[i];
	  }
	return 1;
}
int T;
signed main()
{
	read(T);
	while (T--)
	{
		read(n);read(k);
		scanf("%s%s",a+1,b+1);
		sort(a+1,a+1+n);
		sort(b+1,b+1+n);
		printf("%s\n",solve()?"Yes":"No");
	}
	return  0;
}

/*
1
3 2
aab
zzb
No

*/

