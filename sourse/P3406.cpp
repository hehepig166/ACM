#include <cstdio>
long long n,m,ans,s[100005],S[100005],A[100005],B[100005],C[100005],P[100005];

inline long long min(long long x,long long y){return x>y?y:x;}

int main()
{
	scanf("%lld%lld",&n,&m);
	scanf("%lld",&P[0]);
	for (int i=1; i<m; i++){
		scanf("%lld",&P[i]);
		(P[i]>P[i-1]) ? (s[P[i-1]]++,s[P[i]]--) : ((s[P[i]]++,s[P[i-1]]--));
	}
	
	for (int i=1; i<n; i++)
		scanf("%lld%lld%lld",&A[i],&B[i],&C[i]);
	
	S[0]=ans=0;
	for (int i=1; i<n; i++){
		S[i]=S[i-1]+s[i];
		ans+=min(S[i]*A[i],S[i]*B[i]+C[i]);
	}
	
	printf("%lld",ans);
	
	return 0;
}
