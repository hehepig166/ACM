#include <cstdio>
typedef long long LL;

LL n,a[200][200],ans=-999999999999,S[200][200];

LL max(LL x,LL y){return x<y?y:x;}

int main()
{
	scanf("%lld",&n);
	for (int i=1; i<=n; i++)
		for (int j=1; j<=n; j++)
			scanf("%lld",&a[i][j]);
	
	for (int i=1; i<=n; i++)
		for (int j=1; j<=n; j++)
			S[i][j]=S[i-1][j]+S[i][j-1]-S[i-1][j-1]+a[i][j];
	
	for (int x1=1; x1<=n; x1++)
		for (int y1=1; y1<=n; y1++)
			for (int x2=x1; x2<=n; x2++)
				for (int y2=y1; y2<=n; y2++)
					ans=max(ans,S[x2][y2]-S[x1-1][y2]-S[x2][y1-1]+S[x1-1][y1-1]);
	
	printf("%lld",ans);
	return 0;
}
