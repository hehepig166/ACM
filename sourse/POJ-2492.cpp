#include <cstdio>
int f[2005],v[2005];

int Fa(int x)
{
	if (f[x]==x)
	{
		return x;
	}
	int tmp=f[x];
	f[x]=Fa(tmp);
	v[x]^=v[tmp];
	return f[x];
}

int main()
{
	int T,n,m;
	scanf("%d",&T);
	for (int t=1; t<=T; t++)
	{
		scanf("%d%d",&n,&m);
		for (int i=1; i<=n; i++)
		{
			f[i]=i;
			v[i]=0;
		}
		int fail=0,a,b,fa,fb;
		for (int i=1; i<=m; i++)
		{
			scanf("%d%d",&a,&b);
			if (fail)
			{
				continue;
			}
			fa=Fa(a);
			fb=Fa(b);
			if (fa==fb)
			{
				if (v[a]^v[b]!=1)
				{
					fail=1;
				}
			}
			else
			{
				v[fa]=1^(v[a]^v[b]);
				f[fa]=fb;
			}
		}
		printf("Scenario #%d:\n",t);
		puts(fail ? "Suspicious bugs found!" : "No suspicious bugs found!");
		if (t<T)
			puts("");
	}
	return 0;
}
