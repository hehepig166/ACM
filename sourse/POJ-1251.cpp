#include <cstdio>
#include <algorithm>
using namespace std;
int n;
int f[30],cnt;

int Fa(int x) {return f[x]==x ? f[x] : f[x]=Fa(f[x]);}

struct edge
{
	int u,v,w;
	edge(){}
	edge(int u, int v, int w):u(u),v(v),w(w){}
	bool operator< (edge b) {return this->w < b.w;}
} E[100];

void solve()
{
	int ans=0;
	char U[3],V[3];
	int uu,vv,fu,fv;
	cnt=0;
	for (int i=1,k,ww; i<n; i++)
	{
		scanf("%s%d", U, &k);
		while (k--)
		{
			scanf("%s%d", V, &ww);
			E[cnt++]=edge(U[0]-'A',V[0]-'A',ww);
		}
	}
	sort(E,E+cnt);
	
	for (int i=0; i<26; i++)
		f[i]=i;
	
	for (int i=0; i<cnt; i++)
	{
		uu=E[i].u;
		vv=E[i].v;
		fu=Fa(uu);
		fv=Fa(vv);
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
	while ((scanf("%d",&n),n)!=0)
		solve();
	return 0;
}
