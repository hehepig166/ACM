#include <cstdio>
#include <cstring>
using namespace std;
long long n;

struct Int
{
	//const long long BASE=10000000;
	long long a[1000],len;
	
	Int (){len=1; memset(a,0,sizeof(a));}
	Int (int x){len=1; memset(a,0,sizeof(a)); a[1]=x;}
	Int operator+(const Int &B) const
	{
		Int A=*this;
		Int C;
		long long tmp=0;
		for (C.len=1; C.len<=B.len || C.len<=A.len; C.len++){
			C.a[C.len]=A.a[C.len]+B.a[C.len]+tmp;
			tmp=C.a[C.len]/10000000;
			C.a[C.len]-=tmp*10000000;
		}
		C.len--;
		if (tmp)
			C.a[++C.len]=tmp;
		
		return C;
	}
	void show()
	{
		printf("%lld",a[len]);
		for (int i=len-1; i>0; i--){
			for (long long k=1000000; k; k/=10)
				printf("%d",a[i]/k%10);
		}
	}
} a[6000];

int main()
{
	
	scanf("%lld",&n);
	
	a[1]=1;
	a[2]=2;
	for (int i=3; i<=n; i++)
		a[i]=a[i-1]+a[i-2];
		
	a[n].show();
	return 0;
}
