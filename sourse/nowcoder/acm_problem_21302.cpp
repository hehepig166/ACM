#include <cstdio>
#include <cstring>
#define Ha 1000000007

int main()
{
	char s[100];
	int n;
	long long f[3][100]={0};
	scanf("%s",s);
	n=strlen(s);
	f[(s[0]-'0')%3][0]=1;
	for (int i=1; i<n; i++) {
		for (int j=0; j<3; j++) {
			f[j][i]=(f[(3+j-(s[i]-'0')%3)%3][i-1]+f[j][i-1])%Ha;
		}
		f[(s[i]-'0')%3][i]++;
	}
	printf("%lld\n",f[0][n-1]%Ha);
	return 0;
}
