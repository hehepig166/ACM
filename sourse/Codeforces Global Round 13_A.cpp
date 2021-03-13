#include <cstdio>
using namespace std;
int n,q,s[2],a[100005];

int main()
{
	scanf("%d%d",&n,&q);
	s[0]=s[1]=0;
	for (int i=1; i<=n; i++)
	{
		scanf("%d",&a[i]);
		s[a[i]]++;
	}
	for (int i=1,t,k; i<=q; i++)
	{
		scanf("%d%d",&t,&k);
		if (t==1)
		{
			s[a[k]]--;
			s[a[k]^=1]++;
		}
		else
		{
			puts(s[1]<k ? "0" : "1");
		}
	}
}
