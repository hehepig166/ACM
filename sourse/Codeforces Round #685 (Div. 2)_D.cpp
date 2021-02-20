#include <cstdio>
#include <cmath>
#define sqr(x) ((x)*(x))
using namespace std;
long long T,M,k,d;
double D,m;

int main()
{
	scanf("%lld",&T);
	while (T--)
	{
		scanf("%lld%lld",&d,&k);
		D=double(d)/k;
		m=sqrt(2)*D;
		M=int(m+1);
		while (1)
		{
			if (M*M*k*k>d*d*2)
			{
				M--;
				continue;
			}
			else
			{
				if (M%2==0)
					break;
				else if (sqr((M+1)/2*k)+sqr((M-1)/2*k)<=d*d)
					break;
				else
					M--;
			}
		}
		printf(M%2?"Ashish\n":"Utkarsh\n");
	}
	return 0;
}
/*
1
23441 15599
45 21


*/
