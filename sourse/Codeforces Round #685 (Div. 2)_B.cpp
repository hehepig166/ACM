#include <cstdio>
#define C(x,i,j) (cnt[x][j]-cnt[x][(i)-1])
int T,n,q,l,r,s[200],cnt[2][200];
char he[200];

int main()
{
	scanf("%d",&T);
	while (T--)
	{
		scanf("%d%d",&n,&q);
		scanf("%s",he);
		cnt[1][1]=cnt[0][1]=0;
		for (int i=1; i<=n; i++)
		{
			s[i]=he[i-1]-'0';
			cnt[s[i]][i]=cnt[s[i]][i-1]+1;
			cnt[(s[i]+1)%2][i]=cnt[(s[i]+1)%2][i-1];
		}
		
		while (q--)
		{
			scanf("%d%d",&l,&r);
			
			if (C(s[l],1,l-1)>0 || C(s[r],r+1,n)>0)
			{
				printf("YES\n");
				continue;
			}
			else
			{
				printf("NO\n");
				continue;
			}
			
		}
		
	}
	return 0;
}
