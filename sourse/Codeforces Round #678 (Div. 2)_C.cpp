#include <cstdio>
const long long Ha=1000000007;
int M,n,x,X,pos,l,r,a,b;
long long ans;

int main()
{
	scanf("%d%d%d",&n,&x,&pos);
	ans=1;
	l=a=b=0;
	r=n;
	while (l<r)
	{
		M=(l+r)/2;
		if (M<=pos)
		{
			a++;
			l=M+1;
		}
		else
		{
			b++;
			r=M;
		}
	}
	
	a--;
	if (a>(x-1) || b>(n-x))
	{
		printf("0");
		return 0;
	}
	
	for (int i=1,j=x-1; i<=a; i++,j--)
		ans=ans*j%Ha;
	for (int i=1,j=(n-x); i<=b;i++,j--)
		ans=ans*j%Ha;
	for (int i=n-a-b-1; i; i--)
		ans=ans*i%Ha;
	
	printf("%lld",ans);
	return 0;
}
