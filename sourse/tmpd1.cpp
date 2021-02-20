#include <bits/stdc++.h>
using namespace std;
int n,a[10005],cnt[2],lst[2],tmp;

int main()
{
	scanf("%d",&n);
	a[0]=-1;
	cnt[0]=cnt[1]=0;
	lst[0]=lst[1]=-1;
	for (int i=1,s=0,tmp=0; i<=n; i++)
	{
		scanf("%d",&a[i]);
		if (a[i]==a[i-1])
		{
			s++;
			if (s==1)
			{
				tmp=tmp^1;
				if (lst[tmp]!=a[i])
				{
					cnt[tmp]++;
					lst[tmp]=a[i];
				}
			}
		}
		else
		{
			s=0;
			if (lst[tmp]!=a[i])
			{
				cnt[tmp]++;
				lst[tmp]=a[i];
		 	}
		}
	}
	printf("%d\n",cnt[0]+cnt[1]);
	return 0;
}
