#include <cstdio>
typedef long long LL;
LL N,M,C,a[1005][1005],S[1005][1005],ansx,ansy,ans=-999999999999;

int main()
{
	scanf("%lld%lld%lld",&N,&M,&C);
	for (int i=1; i<=N; i++)
		for (int j=1; j<=M; j++)
			scanf("%lld",&a[i][j]);
	
	for (int i=1; i<=N; i++)
		for (int j=1; j<=M; j++)
			S[i][j]=S[i][j-1]+S[i-1][j]-S[i-1][j-1]+a[i][j];
	
	for (int i=C,tmp; i<=N; i++)
		for (int j=C; j<=M; j++){
			if ((tmp=S[i][j]-S[i-C][j]-S[i][j-C]+S[i-C][j-C]) > ans){
				ans=tmp;
				ansx=i;
				ansy=j;
			}
		}
	
	printf("%lld %lld\n",ansx-C+1,ansy-C+1);
	return 0;
}
