#include <bits/stdc++.h>
using namespace std;
int n,a[100005],cnt[2],lst[2],tmp;

int main()
{
	scanf("%d",&n);
	a[0]=-1;
	a[n+1]=-1;
	for (int i=1; i<=n; i++)
	{
		scanf("%d",&a[i]);
	}
	cnt[0]=cnt[1]=0;
	lst[0]=lst[1]=-1;
	for (int i=1; i<=n; i++)
	{
		
		if (a[i]==lst[0] || a[i]==lst[1] || lst[1]==lst[0])
		{
			if (a[i]!=lst[0])
			{
				cnt[0]++;
				lst[0]=a[i];
			}
			else if (a[i]!=lst[1])
			{
				cnt[1]++;
				lst[1]=a[i];
			}
		}
		else
		{
			if (a[i+1]==lst[0])
			{
				lst[0]=a[i];
				cnt[0]++;
			}
			else
			{
				lst[1]=a[i];
				cnt[1]++;
			}
		}
	}
	printf("%d\n",cnt[0]+cnt[1]);
	return 0;
}
