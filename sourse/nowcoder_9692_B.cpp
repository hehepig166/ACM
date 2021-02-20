#include <cstdio>
int cnt,f;
char s[100005];

int main()
{
	cnt=0;
	while (scanf("%s",s))
	{
		f=0;
		for (int i=0; s[i]>='a' && s[i]<='z'; i++)
		{
			f=1;
			cnt+=s[i]=='a';
		}
		if (!f)
			break;
	}
	printf("%d",cnt);
	return 0;
}
