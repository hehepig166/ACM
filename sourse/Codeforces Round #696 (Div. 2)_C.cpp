#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int T,n,N,K,fail;
int a[3005];
int f[2000005],s[2000005];
int sum,x1;
int ans[2005][2];

int main()
{
	scanf("%d",&T);
	while (T--) {
		scanf("%d",&n);
		N=n*2;
		
		for (int i=1; i<=N; i++) {
			scanf("%d",&a[i]);
			s[a[i]]++;
		}
	
		sort(a+1,a+N+1);
		
		fail=1;
		for (int K=N; fail && K; K--) {
			
			fail=0;
			for (int i=1; i<=N; i++)
				f[a[i]]=s[a[i]];
		
			ans[1][0]=a[N];
			ans[1][1]=a[K];
			if (f[a[N]]>0) {
				f[a[N]]--;
			}
			else {
				fail=1;
				continue;
			}
			if (f[a[K]]>0){
				f[a[K]]--;
			}
			else {
				fail=1;
				continue;
			}
			
			sum=a[N];
			
			for (int cnt=2; !fail && cnt<=n; cnt++) {
				x1=sum;
				while (x1>0 && f[x1]<=0)
					x1--;
				
				if (x1<=0) {
					fail=1;
					break;
				}
				
				f[x1]--;
				if (f[sum-x1]<=0) {
					fail=1;
					break;
				}
				f[sum-x1]--;
				ans[cnt][0]=x1;
				ans[cnt][1]=sum-x1;
				sum=x1;
			}
		}
		
		if (fail) {
			puts("NO");
		}
		else {
			puts("YES");
			printf("%d\n",ans[1][0]+ans[1][1]);
			for (int i=1; i<=n; i++)
				printf("%d %d\n",ans[i][0],ans[i][1]);
		}
		
		for (int i=1; i<=N; i++) {
			s[a[i]]=f[a[i]]=0;
		}
		
	}
	
	
	return 0;
}

/*
4
5
1 2 3 4 5 6 7 14 3 11
2
3 5 1 2
2
1 1 2 4
3
1 1 8 8 64 64

*/
