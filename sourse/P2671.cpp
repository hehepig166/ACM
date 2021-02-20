#include <cstdio>
const long long Ha=10007;

long long s1[100005][2],s2[100005][2],s3[100005][2],s4[100005][2],N,M,n[100005],c[100005],ans=0;

int main()
{
	scanf("%lld%lld",&N,&M);
	for (int i=1; i<=N; i++)
		scanf("%lld",&n[i]);
	for (int i=1; i<=N; i++)
		scanf("%lld",&c[i]);
	
	for (int z=1,C,Z; z<=N; z++)
	{
		C=c[z],Z=z&1;
		ans=(ans+s1[C][Z]+s2[C][Z]*n[z]+s3[C][Z]*z+s4[C][Z]*z*n[z])%Ha;
		s1[C][Z]=(s1[C][Z]+z*n[z])%Ha;
		s2[C][Z]=(s2[C][Z]+z)%Ha;
		s3[C][Z]=(s3[C][Z]+n[z])%Ha;
		s4[C][Z]+=1;
	}
	printf("%lld",ans);
	return 0;
}
/*
s1:		sigma[c[x]==c[z] && ~(x^z&1) ]  (x*n[x])
s2:		sigma[c[x]==c[z] && ]  (x)
s3:		sigma[c[x]==c[z] && ]  (n[x])
s4:		sigma[c[x]==c[z] && ]  (1)
*/
