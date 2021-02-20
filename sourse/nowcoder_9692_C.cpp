#include <cstdio>

int F(int n,int k)	//共 n 个，先手第一次拿 k 个的胜(1)负(0)性 
{
	if (n<=k)
		return 0;
	
	int ret=0;
	
	for (int i=1; i<=k+1; i++)
	{
		ret+=F(n-k,i);
	}
	
	return ret==0;
}

int main()
{
	int T;
	scanf("%d",&T);
	while (T--)
	{
		int n;
		scanf("%d",&n);
		if (n%5==0 || n%5==2)
		{
			printf("Cow\n");
		}
		else
			printf("Pig\n");
	}
	/*
	for (int i=1; i<=100; i++)
		printf("%d",F(i,1));
	*/
	
	/*
	for (int i=1; i<=50; i++)
	{
		printf("\n[%d]\t",i);
		for (int j=1; j<=i; j++)
			printf("%d",F(i,j));
	}
		//printf("[%d]\t%d\n",i,F(i,1));
	*/
	return 0;
}
