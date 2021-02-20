#include <bits/stdc++.h>
#define I id[i]
#define N 200005
using namespace std;
long long n1,n2,n3,n4,a[N],b[N],c[N],d[N],m1,m2,m3;
vector<int> s1[N],s2[N],s3[N];
long long ans;
int id[N],vis[N];

bool cmp1(int x,int y)
{
	return a[x]<a[y];
}
bool cmp2(int x,int y)
{
	return b[x]<b[y];
}
bool cmp3(int x,int y)
{
	return c[x]<c[y];
}

int main()
{
	scanf("%lld%lld%lld%lld",&n1,&n2,&n3,&n4);
	for (int i=1; i<=n1; i++) scanf("%lld",&a[i]);
	for (int i=1; i<=n2; i++) scanf("%lld",&b[i]);
	for (int i=1; i<=n3; i++) scanf("%lld",&c[i]);
	for (int i=1; i<=n4; i++) scanf("%lld",&d[i]);
	
	scanf("%lld",&m1);
	for (int i=1,u,v; i<=m1; i++)
	{
		scanf("%d%d",&u,&v);
		s1[u].push_back(v);
	}
	for (int i=1; i<=n1; i++) id[i]=i;
	for (int i=1; i<=n2; i++) vis[i]=0;
	sort(id+1,id+n1+1,cmp1);
	
	for (int i=1; i<=n1; i++)
		for (int j: s1[I])
			if (vis[j]==i-1)
				vis[j]=i;
				
	for (int i=1; i<=n2; i++)
	{
		if (vis[i]<n1)
			b[i]+=a[id[vis[i]+1]];
		else
			b[i]=2147483647;
	}
	
	scanf("%lld",&m2);
	for (int i=1,u,v; i<=m2; i++)
	{
		scanf("%d%d",&u,&v);
		s2[u].push_back(v);
	}
	for (int i=1; i<=n2; i++)
		id[i]=i;
	for (int i=1; i<=n3; i++)
		vis[i]=0;
	sort(id+1,id+n2+1,cmp2);
	for (int i=1; i<=n2; i++)
	{
		for (int j: s2[I])
		{
			if (vis[j]==i-1)
			{
				vis[j]=i;
			}
		}
	}
	for (int i=1; i<=n3; i++)
	{
		if (vis[i]<n2)
		{
			c[i]+=b[id[vis[i]+1]];		
		}
		else
		{
			c[i]=2147483647;
		}
	}
	
	scanf("%lld",&m3);
	for (int i=1,u,v; i<=m3; i++)
	{
		scanf("%d%d",&u,&v);
		s3[u].push_back(v);
	}
	for (int i=1; i<=n3; i++)
		id[i]=i;
	for (int i=1; i<=n4; i++)
		vis[i]=0;
	sort(id+1,id+n3+1,cmp3);
	for (int i=1; i<=n3; i++)
	{
		for (int j: s3[I])
		{
			if (vis[j]==i-1)
			{
				vis[j]=i;
			}
		}
	}
	for (int i=1; i<=n4; i++)
	{
		if (vis[i]<n3)
		{
			d[i]+=c[id[vis[i]+1]];		
		}
		else
		{
			d[i]=2147483647;
		}
	}
	
	long long ans=2147483647;
	for (int i=1; i<=n4; i++)
		ans=min(ans,d[i]);
	if (ans>=2147483647)
		puts("-1");
	else
		printf("%lld\n",ans);
	return 0;
}


/*
4 3 2 1
1 2 3 4
5 6 7
8 9
10
2
1 2
1 1
2
3 1
3 2
1
1 1

*/
