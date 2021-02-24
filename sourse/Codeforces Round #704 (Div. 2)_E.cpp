#include <bits/stdc++.h>
using namespace std;
#define MaxN 200005

char S[MaxN],T[MaxN];
int n,m,Lid[MaxN][30],Rid[MaxN][30],tmp[30];

int checkR(int x)
{
	int t;
	for (t=1; t<=n && S[t]!=T[1]; t++);
	
	for (int i=2; i<=m; i++)
	{
		int nxt=Rid[t][T[i]];
		while (nxt-t<x && nxt<=n)
			nxt=Rid[nxt][T[i]];
		
		if (nxt>n)
			return 0;
		
		t=nxt;
	}
	
	return 1;
}

int checkL(int x)
{
	int t;
	for (t=n; t>0 && S[t]!=T[m]; t--);
	
	for (int i=m; i>0; i--)
	{
		int nxt=Lid[t][T[i]];
		while (t-nxt<x && nxt>0)
			nxt=Lid[nxt][T[i]];
		
		if (nxt<=0)
			return 0;
		
		t=nxt;
	}
	
	return 1;
}

void solve()
{
	scanf("%d%d",&n,&m);
	scanf("%s%s",S+1,T+1);
	for (int i=1; i<=n; i++) S[i]-='a';
	for (int i=1; i<=m; i++) T[i]-='a';
	
	
	for (int i=0; i<26; i++)
		tmp[i]=0;
	for (int i=1; i<=n; i++)
	{
		for (int j=0; j<26; j++) Lid[i][j]=tmp[j];
		tmp[S[i]]=i;
	}
	for (int i=0; i<26; i++)
		tmp[i]=n+1;
	for (int i=n; i>=1; i--)
	{
		for (int j=0; j<26; j++) Rid[i][j]=tmp[j];
		tmp[S[i]]=i;
	}
	
	int L,R,M,ans=0;
	
	for (L=0,R=n,M=(L+R)/2; L<R; M=(L+R)/2)
	{
		if (checkR(M) || checkL(M))
			ans=L=M;
		else
			R=M-1;
	}
	
	printf("%d\n",ans);
}

int main()
{
	solve();
	return 0;
}
