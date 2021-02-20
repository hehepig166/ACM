#include <cstdio>
#include <cstring>
using namespace std;

int p[10005],f[100005],num;

void get_p(){
	int N=100000;
	memset(f,0,sizeof(f));
	f[1]=1;
	for (int i=2; i<=N; i++){
		if (!f[i]) p[++num]=i;
		for (int j=1; j<=num && p[j]*i<=N; j++){
			f[p[j]*i]=1;
			if (i%p[j]==0) break;
		}
	}
}


int main()
{

	get_p();
	
	int T;
	scanf("%d",&T);
	while (T--) {
		long long d,ans=1,cnt=0;
		scanf("%lld",&d);
		for (int i=1; i<=num; i++) {
			if (p[i]>d) {
				if (cnt==0) {
					ans*=p[i];
					cnt=1;
					continue;
				}
				if (cnt==1) {
					if (p[i]-ans<d) {
						continue;
					}
					ans*=p[i];
					break;
				}
			}
		}
		printf("%lld\n",ans);
	}
	return 0;
}
