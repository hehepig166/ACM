#include <cstdio>
int T,s[2],c[2],h,n;

int main()
{
	char ch=-1;
	scanf("%d",&T);
	while (T--)
	{
		scanf("%d%d%d%d",&n,&c[0],&c[1],&h);
		s[0]=s[1]=0;
		for (ch=getchar(); ch!='0' && ch!='1'; ch=getchar());
		for (; ch=='0' || ch=='1'; ch=getchar())
			s[ch-'0']++;
		
		if (c[0]>c[1]+h)
		{
			printf("%d\n",s[1]*c[1]+s[0]*(c[1]+h));
			continue;
		}
		if (c[1]>c[0]+h)
		{
			printf("%d\n",s[0]*c[0]+s[1]*(c[0]+h));
			continue;
		}
		printf("%d\n",s[0]*c[0]+s[1]*c[1]);
	}
} 
