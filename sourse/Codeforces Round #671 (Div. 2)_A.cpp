#include <cstdio>
#include <cstring>
using namespace std;


int main()
{
	int T,n,s1,s2,tmp,s[2][2];
	scanf("%d",&T);
	while (T--)
	{
		scanf("%d",&n);
		memset(s,0,sizeof(s));
		char ch=getchar();
		while (ch<'0' || ch>'9')
			ch=getchar();
		for (int i=1; i<=n; i++)
		{
			tmp=ch-'0';
			s[i%2][tmp%2]++;
			ch=getchar();
		}
		
		if (n==1)
		{
			if (tmp%2==0)
				printf("2\n");
			else
				printf("1\n");
			continue;
		}
		
		s1=s[1][0]+s[1][1];
		s2=s[0][0]+s[0][1];
		if (s1==s2)
		{
			if (s[0][0]>0)
				printf("2\n");
			else
				printf("1\n");
			continue;
		}
		if (s[1][1]>0)
			printf("1\n");
		else
			printf("2\n");
	}
	return 0;
}
