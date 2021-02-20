#include <cstdio>
#include <algorithm>
using namespace std;
int n,cnt,a[500005],c[500005],f[500005],g[500005],OK[500005];
bool cmp(int x,int y){return a[x]<a[y];}
int Fa(int x){
	return (f[x]==x) ? (x) : (f[x]=Fa(f[x]));
}

int main()
{
	cnt=1;
	scanf("%d",&n);
	for (int i=0; i<=500000; i++)
		g[i]=OK[i]=0;
	for (int i=1; i<=n; i++)
	{
		scanf("%d",&a[i]);
		c[i]=f[i]=i;
	}
	sort(c+1,c+n+1,cmp);
	
	OK[0]=1;
	for (int i=1,I=c[i]; i<=n; I=c[++i])
	{
		(a[I]!=a[I-1]) ? cnt++ : 1;
		
		if (cnt==2)
		{
			g[f[I]]=cnt;
			OK[a[I]]=1;
			continue;
		}
		
		if (g[Fa(I+1)]>=cnt-1 && g[Fa(I-1)]<cnt-1)
		{
			f[I]=f[I+1],OK[a[I]]=1;
		}
		if (g[Fa(I+1)]<cnt-1 && g[Fa(I-1)]>=cnt-1)
		{
			f[I]=f[I-1],OK[a[I]]=1;
		}
		if (g[Fa(I+1)]>=cnt-1 && g[Fa(I-1)]>=cnt-1)
		{
			f[I]=f[I-1]=f[I+1],OK[a[I]]=1;
		}
		
		g[f[I]]=cnt;
	}
	
	for (int i=0; i<=500000; i++)
		if (!OK[i])
		{
			printf("%d\n",i+1);
			break;
		}
	/*
	for (int i=1; i<=n; i++)
		printf("%d ",g[f[i]]);
	*/
	return 0;
}

/*
5
2 9 9 1 9 


10
2 9 8 11 6 14 1 1 7 17 
*/
