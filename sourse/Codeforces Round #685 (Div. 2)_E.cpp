#include <cstdio>
int AA,BB,CC,DD,EE,FF,A,B,C,D,E,F,a[70000],n;

int main()
{
	scanf("%d",&n);
	
	printf("XOR 1 2\n");
		fflush(stdout);
	scanf("%d",&AA);
	printf("XOR 2 3\n");
		fflush(stdout);
	scanf("%d",&BB);
	printf("OR 1 2\n");
		fflush(stdout);
	scanf("%d",&CC);
	printf("OR 2 3\n");
		fflush(stdout);
	scanf("%d",&DD);
	printf("OR 1 3\n");
		fflush(stdout);
	scanf("%d",&EE);
	printf("XOR 1 4\n");
		fflush(stdout);
	scanf("%d",&FF);
	for (int i=0,j=1; i<n; i++,j=j*2)
	{
		A=(AA&j)>0;
		B=(BB&j)>0;
		C=(CC&j)>0;
		D=(DD&j)>0;
		E=(EE&j)>0;
		F=(FF&j)>0;
		for (int a1=0; a1<=1; a1++)
			for (int a2=0; a2<=1; a2++)
				for (int a3=0; a3<=1; a3++)
					for (int a4=0; a4<=1; a4++)
						if (((a1^a2)==A && (a2^a3)==B && (a1|a2)==C && (a2|a3)==D && (a1|a3)==E && (a1^a4)==F))
						{
							a[1]+=a1*j;
							a[2]+=a2*j;
							a[3]+=a3*j;
							a[4]+=a4*j;
						}
	}
	
	for (int i=5,tmp; i<=n; i++)
	{
		printf("XOR 1 %d\n",i);
			fflush(stdout);
		scanf("%d",&tmp);
		a[i]=a[1]^tmp;
	}
	
	printf("! ");
	for (int i=1; i<=n; i++)
		printf("%d ",a[i]);
	printf("\n");
	fflush(stdout);
		
	return 0;
}
/*
4 0 6 0 7 3 3
*/
