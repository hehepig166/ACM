#include <bits/stdc++.h>
using namespace std;

void solve()
{
	int X,Y,U=0,R=0,D=0,L=0;
	char s[100005];
	scanf("%d%d",&X,&Y);
	scanf("%s",s);
	for (int i=0; s[i]; i++)
	{
		if (s[i]=='U')
			U++;
		else if (s[i]=='L')
			L++;
		else if (s[i]=='R')
			R++;
		else if (s[i]=='D')
			D++;
		else
			break;
	}
	if (X>0 && R<X)
		puts("NO");
	else if (X<0 && L<-X)
		puts("NO");
	else if (Y>0 && U<Y)
		puts("NO");
	else if (Y<0 && D<-Y)
		puts("NO");
	else
		puts("YES");
	
}

int main()
{
	int T;
	scanf("%d",&T);
	while (T--)
	{
		solve();
	}
	return 0;
}
