//https://vjudge.net/problem/POJ-1182
#include <cstdio>
#define N 50005

int f[N];	//并查集 
int g[N];	//与父亲的关系 (0:x=f 1:x>f 2:x<f) 
int ans,n,k,D,a,b,fa,fb,p;

int Fa(int x)
{
	if (f[x]!=x) {
		int tmp=f[x];
		f[x]=Fa(tmp);
		g[x]=(g[x]+g[tmp])%3;
	}
	return f[x];
}

void init()
{
	ans=0;
	for (int i=1; i<=n; i++) {
		f[i]=i;
		g[i]=0;
	}
}

int main()
{
	scanf("%d%d",&n,&k);
	init();
	while (k--) {
		scanf("%d%d%d",&D,&a,&b);
		
		if (a>n || b>n) {
			ans++;
			continue;
		}
		
		p=(D==2);	//a->b = p
		
		fa=Fa(a);
		fb=Fa(b);
		if (fa==fb) {
			ans+=((g[a]-g[b]+3)%3!=p);
		}
		else {
			f[fa]=fb;
			g[fa]=(p+g[b]-g[a]+3)%3;
		}
	}
	printf("%d\n",ans);
	return 0;
}
