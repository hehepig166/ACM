#include <cstdio>
#include <algorithm>
using namespace std;
int P,R;

struct edge
{
	int u,v,w;
	edge(){};
	edge(int u, int v, int w) : u(u), v(v), w(w) {};
	bool operator< (const edge &b) {return this->w < b.w;}
} E[3000];

int f[100];
int Fa(int x) {return f[x]==x ? x : f[x]=Fa(f[x]);}

void solve()
{
	int ans=0;

	for (int i=1; i<=R; i++)
		scanf("%d%d%d",&E[i].u, &E[i].v, &E[i].w);
	sort(E+1, E+R+1);

	for (int i=1; i<=P; i++)
		f[i]=i;

	for (int i=1,fu,fv; i<=R; i++)
	{
		fu=Fa(E[i].u);
		fv=Fa(E[i].v);
		if (fu!=fv)
		{
			f[fu]=fv;
			ans+=E[i].w;
		}
	}

	printf("%d\n",ans);
}

int main()
{
	while (1)
	{
		scanf("%d%d",&P,&R)!=2;
		if (P==0)
			break;
		solve();
	}
	return 0;
}