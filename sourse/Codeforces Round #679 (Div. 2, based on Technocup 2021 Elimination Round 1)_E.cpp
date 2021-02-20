#include <cstdio>

int main()
{
	scanf("%d",&T);
	while (T--)
	{
		scanf("%d%d%d%d",&a,&b,&c,&d);
		
		S=k=0;
		for (int i=0,j=c+d+1; i<=j; i++)
		{
			if (i%d==0)
				S+=a;
			if ((i-1)%d==0)
				k++;
			if (i>d && (i-d-1)%d==0)
				k--;
			S-=b*k;
			
			if (S>ans) ans=S;
		}
		
	}
	return 0;
}
