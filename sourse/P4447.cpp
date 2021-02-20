#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
int n,cnt,ans,a[100005],lst[100005],num[100005];

int main()
{
	ans=2147483647;
	scanf("%d",&n);
	for (int i=1; i<=n; i++) scanf("%d",&a[i]);
	sort(a+1,a+n+1);
	memset(num,0,sizeof(num));
	cnt=1;
	lst[1]=a[1];
	num[1]=1;
	for (int i=2; i<=n; i++)
	{
		int tmp=2147483647,w=0,ii=a[i]-1;
		for (int j=1; j<=cnt; j++)
			if (lst[j]==ii && num[j]<tmp) w=j,tmp=num[j];
		if (num[w])
		{
			lst[w]=a[i];
			num[w]++;
			continue;
		}
		cnt++;
		lst[cnt]=a[i];
		num[cnt]=1;
	}
	for (int i=1; i<=cnt; i++)
		if (ans>num[i]) ans=num[i];
	printf("%d",ans);
}
