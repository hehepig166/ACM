#include <cstdio>
#include <cstring>
using namespace std;
long long T,n,a,k,ans,s[50];

int main()
{
	//freopen("1.txt","r",stdin);
	scanf("%lld",&T);
	while (T--)
	{
		ans=0;
		memset(s,0,sizeof(s));
		scanf("%lld",&n);
		for (int i=1; i<=n; i++)
		{
			scanf("%lld",&a);
			for (k=31; (1ll<<k)>a; k--);
			s[k]++;
		}
		for (int i=0; i<=30; i++)
			ans+=s[i]*(s[i]-1)/2;
		printf("%lld\n",ans);
	}
	return 0;
}
