#include <cstdio>
//#define Abs(x) ((x)>0 ? (x) : (-(x)))
int a[100005],b[100005],ns,l,r,mid,n;

inline int Abs(int x){return x>0 ? x : -x;}

int OK(int x)
{
	int F,f,t,s,pos,neg;
	for (int k=1; k<=6; k++)
	{
		t=b[1]-a[k];
		F=1;
		for (int i=2; i<=n && F; i++)
		{
			f=0,tmp_pos,tmp_neg;
			
			for (int j=1; j<=6 && !f; j++)
			{
				s=b[i]-a[j];
				if (Abs(s-t)<=x)
				{
					
				}
				f=;
			}
			
			F+=f;
		}
		if (F)
			return 1;
	}
	return 0;
}

int main()
{
	for (int i=1; i<=6; i++)
		scanf("%d",&a[i]);
	scanf("%d",&n);
	for (int i=1; i<=n; i++)
		scanf("%d",&b[i]);
	
	l=0,r=1e9;
	while (l<r)
	{
		mid=((l+r)>>1);
		if (OK(mid))
			r=mid,ans=mid;
		else
			l=mid+1;
	}
	printf("%d",ans);
	return 0;
}
