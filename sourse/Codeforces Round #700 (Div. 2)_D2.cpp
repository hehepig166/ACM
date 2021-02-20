#include <bits/stdc++.h>
#define N 100//005
using namespace std;
int n,a[N],b[N],lst[N],M[2],num;
int f[N][2];

int main()
{
	scanf("%d",&n);
	for (int i=1; i<=n; i++)
	{
		scanf("%d",&b[i]);
	}
	
	num=0;
	a[0]=-1;
	for (int i=1; i<=n; )
	{
		a[++num]=b[i];
		i++;
		while (i<=n && b[i]==b[i-1])
			i++;
	}
	a[num+1]=-1;
	
	for (int i=1; i<=n; i++)
	{
		b[i]=0;
	}
	for (int i=1; i<=num; i++)
	{
		lst[i]=b[a[i]];
		b[a[i]]=i;
	}
	
	//f[i][x]:	minval s.t. 1..i with a[i] belongint to x
	//M[x]	: 	min{ f[k][x]-k }
	f[1][0]=f[1][1]=1;
	M[0]=M[1]=0;
	
	for (int i=2; i<=num; i++)
	{
		for (int j=0; j<=1; j++)
		{
			f[i][j]=10000000;
			if (lst[i]>0)
			{
				f[i][j]=min(f[i][j], f[lst[i]][j]+(i-lst[i])-1);
			}
			
			f[i][j]=min(f[i][j], M[j^1]+i);
			
			M[j]=min(M[j], f[i][j]-i);
		}
	}
	
	printf("%d\n",min(f[num][0],f[num][1]));
	return 0;
}
