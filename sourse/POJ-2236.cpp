//https://vjudge.net/problem/POJ-2236
#include <cstdio>
#define N 1005

int f[N];
bool broken[N];
int n,d,D,p,q;
char Q[3];
int X[N],Y[N];

int Fa (int x)
{
	return f[x]==x ? x : f[x]=Fa(f[x]);
}

inline int fail(int u,int v)
{
	return (X[u]-X[v])*(X[u]-X[v])+(Y[u]-Y[v])*(Y[u]-Y[v])>D;
}

int main()
{
	
	scanf("%d%d",&n,&d);
	D=d*d;
	for (int i=1; i<=n; i++) {
		broken[i]=1;
		f[i]=i;
		scanf("%d%d",&X[i],&Y[i]);
	}
	
	while (scanf("%s",Q)!=EOF) {
		if (Q[0]=='O') {
			scanf("%d",&p);
			for (int i=1; i<=n; i++) {
				if (i!=p && !broken[i] && !fail(p,i)) {
					f[Fa(i)]=Fa(p);
				}
			}
			broken[p]=0;
		}
		else {
			scanf("%d%d",&p,&q);
			puts(Fa(p)==Fa(q) ? "SUCCESS" : "FAIL");
		}
	}
	
	return 0;
}
