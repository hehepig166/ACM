#include <bits/stdc++.h>
using namespace std;

int main()
{
	char s[100];
	long long n,tmp,ans,a[100];
	
	scanf("%s",s);
	n=strlen(s);
	for (long long i=0; i<n; i++)
		a[i]=s[i]-'0';
	
	tmp=ans=0;
	for (long long i=0; i<n; i++)
	{
		a[i]+=tmp;
		ans+=(abs(a[i])*(n-i));
		tmp-=a[i];
	}
	
	printf("%lld\n",ans);
	return 0;
}
