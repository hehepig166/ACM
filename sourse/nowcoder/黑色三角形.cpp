#include <bits/stdc++.h>
using namespace std;

int main()
{
	int f[55][55];
	char a[55][55];
	int n,m,k,ans,tmp,tans,I,J;
	
	scanf("%d%d%d",&n,&m,&k);
	memset(f,0,sizeof(f));
	for (int i=0; i<n; i++)
		scanf("%s",a[i]);
	
	ans=0;
	for (tans=1,tmp=min(n,m); tans<=tmp; tans++) {
		for (int i=1,j=tans-i; j>0; i++,j--) {
			I=n-i,J=m-j;
			if (a[I][J]!='#' && !f[I][J]) {
				k--;
				f[I][J]=1;
				a[I][J]='#';
			}
		}
		
		for (int i=1,j=tans+1-i; j>0; i++,j--) {
			I=n-i,J=m-j;
			if (a[I][J]=='.') {
				k=-1;
				break;
			}
		}
		
		if (k<0) {
			break;
		}
		ans+=tans;
	}
	
	printf("%d\n",ans ? ans : -1);
	return 0;
}
