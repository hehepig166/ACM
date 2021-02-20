#include <cstdio>
int n,s,cnt,a[100005],b[100005][3];


int main()
{	
	scanf("%d",&n);
	for (int i=1; i<=n; i++)
		scanf("%d",&a[i]);
	
	s=cnt=0;
	for (int i=1; i<=n; i++)
		s^=a[i];
	
	
	if (n%2==0 && s!=0)
	{
		printf("NO\n");
		return 0;
	}
	if (n%2==0)
		n--;
	printf("YES\n");
	for (int i=1,j=n-2; i<n; i+=2)
	{
		cnt++;
		
		if (i>j)
		{
			b[cnt][0]=n-2;
			b[cnt][1]=n-1;
			b[cnt][2]=n;
			break;
		}
		
		b[cnt][0]=i;
		b[cnt][1]=i+1;
		b[cnt][2]=i+2;
	}
	
	
	for (int i=n-2; i>0; i-=2)
	{
		cnt++;
		
		if (i<3)
		{
			b[cnt][0]=1;
			b[cnt][1]=2;
			b[cnt][2]=3;
			break;
		}
		
		b[cnt][0]=i;
		b[cnt][1]=i-1;
		b[cnt][2]=i-2;
	}
	
	printf("%d\n",cnt);
	for (int i=1; i<=cnt; i++)
		printf("%d %d %d\n",b[i][0],b[i][1],b[i][2]);
	//printf("%d",s);
	return 0;
}

/*
11
15 84 3 2 485645 12 4 23 123 4 1
*/
