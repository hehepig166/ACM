#include <cstdio>
#include <cstring>
using namespace std;
long long n,a[500005],s[500005],lst[500005],cnt,ans,S;
long long l[3][500005],b[500005];

int main(){
	scanf("%lld",&n);
	for (int i=1; i<=n; i++) scanf("%lld",&a[i]);
	
	for (int i=1; i<=n; i++){
		s[i]=(s[lst[a[i]]]+1)%3;
		lst[a[i]]=i;
		if (s[i]==1) S++;
		if (s[i]==0) S--;
		if (S==0) cnt++,b[cnt]=i,ans++;
	}
	for (int i=1; i<=cnt; i++){
		l[0][i]=l[0][i-1]+1;
		ans+=l[0][i-1];
		for (int j=1; j<3; j++){
			if (b[i]-j<=0 || a[b[i]-j]!=a[b[i]-j+1]) break;
			l[j][i]=l[j][i-1]+1;
		}
		for (int j=1; j<3; j++){
			if (b[i]+j>n || a[b[i]+j]!=a[b[i]+j-1]) break;
			ans+=l[3-j][i-1];
		}
	}
	printf("%lld",ans);
}
/*
S		
s[i]	num of a[i] in a[1]..a[i]
lst[i]	j that a[j] is the last i till now 


10
1 1 2 2 2 1 1 2 2 2
*/
