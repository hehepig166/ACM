#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
int T,n,l,GG,a[100005];
double t1[100005],t2[100005],T1,T2,v1,v2,s,ans;

int main()
{
	scanf("%d",&T);
	while (T--)
	{
		GG=0;
		scanf("%d%d",&n,&l);
		a[0]=0,a[n+1]=l;
		for (int i=1; i<=n; i++) scanf("%d",&a[i]);
		memset(t1,0,sizeof(t1));
		memset(t2,0,sizeof(t2));
		sort(a+1,a+n+1);
		for (int i=1,j=n+1; i<=j; i++)
			t1[i]=t1[i-1]+1.0*(a[i]-a[i-1])/i;
		for (int i=n; i>=0; i--)
			t2[i]=t2[i+1]+1.0*(a[i+1]-a[i])/(n-i+1);
		t1[0]=t2[n+1]=0;
		for (int i=1; i<=n && !GG; i++)
		{
			if (t1[i]==t2[i])
			{
				ans=t1[i];
				GG=1;
				break;
			}
			if (t1[i]<t2[i] && t1[i+1]>t2[i+1])
			{
				T1=t1[i],T2=t2[i+1],v1=i+1,v2=n-i+1,s=a[i+1]-a[i];
				ans=(T1*v1+T2*v2+s)/(v1+v2);
				GG=1;
				break;
			}
		}
		if (!GG)
		{
			if (t1[1]>t2[1])
			{
				int i=0;
				T1=t1[i],T2=t2[i+1],v1=i+1,v2=n-i+1,s=a[i+1]-a[i];
				ans=(T1*v1+T2*v2+s)/(v1+v2);
			}
			if (t2[n]>t1[n])
			{
				int i=n;
				T1=t1[i],T2=t2[i+1],v1=i+1,v2=n-i+1,s=a[i+1]-a[i];
				ans=(T1*v1+T2*v2+s)/(v1+v2);
			}
		}
		printf("%.15lf\n\n",ans);
	}
}
