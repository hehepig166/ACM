#include <cstdio>
#include <iostream>
#include <cstring>
using namespace std;
#define N 200005
int T,n,a[N];
int s[N],p[N],Smark,Pmark;

int main()
{
	
	scanf("%d",&T);
	while (T--) {
		//memset(s,0,sizeof(s));
		//memset(p,0,sizeof(p));
		scanf("%d",&n);
		for (int i=1; i<=n; i++)
			scanf("%d",&a[i]);
		
		s[0]=0;
		Smark=n+1;
		for (int i=1; i<=n; i++) {
			s[i]=a[i]-s[i-1];
			if (s[i]<0) {
				Smark=i;
				break;
			}
		}
		
		p[n+1]=0;
		Pmark=0;
		for (int i=n; i>=1; i--) {
			p[i]=a[i]-p[i+1];
			if (p[i]<0) {
				Pmark=i;
				break;
			}
		}
		
		//case0
		if (Smark==n+1 && s[n]==0) {
			puts("YES");
			continue;
		}
		
		//case1
		if (Smark<Pmark-1) {
			puts("NO");
			continue;
		}
		
		//case2
		int fail=1;
		for (int i=Smark; i+1>=Pmark; i--) if (i>0 && i<n) {
			swap(a[i],a[i+1]);
			
			//a[i]=   s[i-1] + (a[i]-s[i-1])
			//a[i+1]= p[i+2] + (a[i+1]-p[i+2])
			
			if (a[i]-s[i-1]>=0 && a[i+1]-p[i+2]>=0 && a[i]-s[i-1]==a[i+1]-p[i+2] && s[i-1]>=0 && p[i+2]>=0) {
				fail=0;
				break;
			}
			
			swap(a[i],a[i+1]);
		}
		puts(fail ? "NO" : "YES");
	}
	return 0;
}
