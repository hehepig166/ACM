#include <cstdio>

int he(char ch)
{
	if (ch>='0' && ch<='9') return ch-'0';
	if (ch>='A' && ch<='F') return ch-'A'+10;
	return -1;
}

char ha(int x)
{
	if (x>=0 && x<=9) return (char)('0'+x);
	if (x>=10 && x<=15) return (char)('A'+x-10);
	return -1;
}

int main()
{
	long long n,m,A,tmp;
	
	scanf("%lld",&n);
	char ch;
	
	for (ch=getchar(); he(ch)<0; ch=getchar())
		continue;
	
	for (A=0; (tmp=he(ch))>=0; ch=getchar())
		A=A*n+tmp;
	
	scanf("%lld",&m);
	for (tmp=1; A/tmp; tmp*=m)
		continue;
	
	for (tmp/=m; tmp; tmp/=m){
		printf("%c",ha(A/tmp));
		A%=tmp;
	}
	
	return 0;
}
/*
10
9999999
16
*/
