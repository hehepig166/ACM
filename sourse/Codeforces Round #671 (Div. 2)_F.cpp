#include <cstdio>
#include <algorithm>
#include <cmath>
using namespace std;
int n;

struct Pt
{
	int xx,yy;
}a[1005];

bool cmp1(Pt x,Pt y)
{
	if (x.xx!=y.xx) return x.xx<y.xx;
	return x.yy<y.yy;
}
bool cmp2(Pt x,Pt y)
{
	if (x.yy!=y.yy) return x.yy<y.yy;
	return x.xx<y.xx;
}

void upd(int x,int y,int s)
{
	if (f[x]==f[y]) A[f[x]]=min	
}

int main()
{
	scanf("%d",&n);
	for (int i=1; i<=n; i++)
		scanf("%d%d",&a[i].x,&a[i].y);
	
	//|
	sort(a+1,a+n+1,cmp1);
	for (int i=2; i<=n; i++)
	{
		if (a[i].xx==a[i-1])
		{
			upd(i,i-1,abs(a[i].yy,a[i-1].yy));
		}
	}
}

