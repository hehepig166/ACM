#include <cstdio>
const double Pi=3.1415926535;
int a,b,R,H,L;
double d,ans;

int main()
{
	int T;
	scanf("%d",&T);
	while (T--)
	{
		scanf("%d%d%d%d",&a,&b,&R,&H);
		
		L=(a-b+360)%360;
		L=(360-L<L) ? 360-L : L;
		
		d=Pi*2*R/360*L;
		
		ans=d*d+H*H;
		
		printf("%.2f\n",ans);
		
	}
	
	return 0;
}
