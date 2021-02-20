#include <cstdio>
int a[300005],T,n,q,l,r,f[300005];
long long ans;

void swap(int &x,int &y)
{
	int tmp=x;
	x=y,y=tmp;
}

void ins(int x)
{
	if (x==0 || x>n || f[x])
		return;
	f[x]=1;
	if (a[x]<a[x+1] && a[x]<a[x-1])
		ans-=a[x];
	if (a[x]>a[x+1] && a[x]>a[x-1])
		ans+=a[x];
}

void del(int x)
{
	if (x==0 || x>n || !f[x])
		return;
	f[x]=0;
	if (a[x]<a[x+1] && a[x]<a[x-1])
		ans+=a[x];
	if (a[x]>a[x+1] && a[x]>a[x-1])
		ans-=a[x];
}

int main()
{
	//freopen("1.txt","r",stdin);
	scanf("%d",&T);
	while (T--)
	{
		scanf("%d%d",&n,&q);
		for (int i=1; i<=n; i++)
			scanf("%d",&a[i]),f[i]=0;
		a[0]=a[n+1]=ans=0;
		for (int i=1; i<=n; i++)
			ins(i);
		printf("%lld\n",ans);
		while (q--)
		{
			scanf("%d%d",&l,&r);
			del(l-1); del(l); del(l+1);
			del(r-1); del(r); del(r+1);
			swap(a[l],a[r]);
			ins(l-1); ins(l); ins(l+1);
			ins(r-1); ins(r); ins(r+1);
			printf("%lld\n",ans);
		}
	}
}
