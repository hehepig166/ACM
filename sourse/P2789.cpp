#include <cstdio>

int main()
{
	int n;
	scanf("%d",&n);
	if (n<=2){
		printf("%d\n",n);
		return 0;
	}
	printf("%d\n",n*(n-1)/2-1);
	return 0;
}
