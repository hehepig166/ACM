#include <cstdio>
#include <algorithm>
using namespace std;
long long n,m,ans,tmp,cnt,f[200005];

struct edge
{
	long long u,v,w;
} E[200005];

bool cmp(edge x, edge y)
{
	return x.w<y.w;
}

long long Fa(long long x)
{
	return f[x]==x ? x : f[x]=Fa(f[x]);
}

int main()
{
	scanf("%lld%lld",&n,&m);
	for (int i=1; i<=m; i++)
		scanf("%lld%lld%lld",&E[i].u,&E[i].v,&E[i].w);
	
	for (int i=1; i<=n; i++)
		f[i]=i;
	
	sort(E+1,E+m+1,cmp);
	
	ans=0;
	cnt=1;
	for (tmp=n-1; tmp && cnt<=m; tmp--)
	{
		while (Fa(E[cnt].u) == Fa(E[cnt].v) && cnt<=m)
			cnt++;
		
		if (cnt<=m)
		{
			f[Fa(E[cnt].u)]=Fa(E[cnt].v);
			ans+=E[cnt].w;
		}
		else
		{
			cnt=m+5;
			break;
		}
	}
	
	printf("%lld", cnt<=m && tmp==0 ? ans:-1);
	return 0;
}
/*
4 6
1 2 1
1 2 1
1 3 1
1 4 1
2 3 1
3 4 1

7 6
1 2 1
1 3 1
1 4 0
1 5 0
1 6 1
1 7 1

7 6
1 2 1
1 3 1
1 4 0
1 5 0
1 6 1
1 2 0
*/
