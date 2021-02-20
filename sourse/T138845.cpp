#include <cstdio>
int a[30],ans=0;

int main()
{
	char ch;
	ch=getchar();
	while (ch<'a' || ch>'z')
		ch=getchar();
	while (ch>='a' && ch<='z')
	{
		a[ch-'a']++;
		if (a[ch-'a']>ans) ans=a[ch-'a'];
		ch=getchar();
	}
	printf("%d",ans);
	return 0;
}
