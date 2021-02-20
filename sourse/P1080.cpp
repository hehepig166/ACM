#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
int n,a[10005],b[10005],c[10005];
//long long d1[10005],k,ans=0;
bool cmp(int x,int y){return a[x]*b[x]<a[y]*b[y];}

struct gjd
{
	int a[1000],dig;	//一个a[]为十进制4位 
	gjd(){memset(a,0,sizeof(a)); dig=1;}
}d1[10005],k,ans;

gjd mul(gjd A,int x) 
{
	gjd ret;
	ret.dig=A.dig;
	for (int i=1; i<=A.dig; i++)
	{
		ret.a[i]+=A.a[i]*x;
		if (ret.a[i]>10000)
		{
			ret.a[i+1]+=ret.a[i]/10000;
			ret.a[i]%=10000;
			if (i+1>ret.dig) ret.dig=i+1;
		}
	}
	return ret;
}

gjd divi(gjd A,int x)
{
	gjd ret;
	for (int i=A.dig,c=0; i; i--)
	{
		ret.a[i]=(A.a[i]+10000*c)/x;
		c=(A.a[i]+10000*c)%x;
	}
	if (ret.a[A.dig]>0) ret.dig=A.dig;
	else ret.dig=A.dig-1;
	return ret;
}

bool dayu(gjd A, gjd B)
{
	if (A.dig!=B.dig) return A.dig>B.dig;
	for (int i=A.dig; i; i--)
		if (A.a[i]!=B.a[i])
			return A.a[i]>B.a[i];
	return 0;
}

void wt(gjd A)
{
	printf("%d",A.a[A.dig]);
	for (int i=A.dig-1; i; i--)
		for (int j=1000; j; j/=10)
			printf("%d",A.a[i]/j%10);
}

int main()
{
	//freopen("1.txt","r",stdin);
	scanf("%d%d%d",&n,&a[0],&b[0]);
	for (int i=1; i<=n; i++) scanf("%d%d",&a[i],&b[i]),c[i]=i;
	sort(c+1,c+n+1,cmp);
	d1[0].a[1]=d1[0].dig=1;
	d1[0]=mul(d1[0],a[0]);
	for (int i=1; i<=n; i++)
	{
		d1[i]=mul(d1[i-1],a[c[i]]);
		//d1[i]=d1[i-1]*a[c[i]];
		k=divi(d1[i-1],b[c[i]]);
		//k=d1[i-1]/b[c[i]];
		if (dayu(k,ans)) ans=k;
		//if (k>ans) ans=k;
	}
	wt(ans);
	//printf("%d",ans);
	return 0;
}
