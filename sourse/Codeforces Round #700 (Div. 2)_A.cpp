#include <bits/stdc++.h>
using namespace std;
int T;
int n;
char s[100];

void solve()
{
	scanf("%s",s);
	n=strlen(s);
	for (int i=0; i<n; i++)
	{
		if (i%2==0)	//A small
		{
			s[i]=(s[i]=='a' ? 'b' : 'a');
		}
		else		//B large
		{
			s[i]=(s[i]=='z' ? 'y' : 'z');
		}
	}
	printf("%s\n",s);
}

int main()
{
	scanf("%d",&T);
	while (T--)
	{
		solve();
	}
	return 0;
}
