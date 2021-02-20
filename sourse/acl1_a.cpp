#include <cstdio>
#include <algorithm>
#include <cmath>
#define INF 50
using namespace std;
int n,X[INF],Y[INF],a[INF],top,Q[INF],f[INF],cnt[INF],Min[INF];

bool cmp(int x,int y){return Y[x]<Y[y];}

int Fa(int x){
	if (f[x]==x) return x;
	f[x]=Fa(f[x]);
	return f[x];
}

int main()
{
	scanf("%d",&n);
	top=0;
	for (int i=1; i<=n; i++)
	{
		scanf("%d%d",&X[i],&Y[i]);
		a[i]=i;
	}
	sort(a+1,a+n+1,cmp);
	for (int i=1; i<=n; i++){
		Min[a[i]]=X[a[i]];
		while (top>0 && Min[Q[top]]<X[a[i]])
		{
			f[Q[top]]=a[i];
			cnt[a[i]]+=cnt[Q[top]];
			Min[a[i]]=min(Min[Q[top]],Min[a[i]]);
			top--;
		}
		Q[++top]=a[i];
		f[a[i]]=a[i];
		cnt[a[i]]++;
	}
	for (int i=1; i<=n; i++)
		printf("%d\n",cnt[Fa(i)]);
}
