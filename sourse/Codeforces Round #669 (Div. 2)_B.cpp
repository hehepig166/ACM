#include <cstdio>
#include <algorithm>
using namespace std;
int n,t,a[2000],b[2000],c[2000],lgg,gg,cnt,tmp1,tmp2;

int GCD(int b,int c){return c ? GCD(c,b%c) : b;}

int main(){
	scanf("%d",&t);
	while (t--){
		scanf("%d",&n);
		for (int i=1; i<=n; i++) scanf("%d",&a[i]),c[i]=1;
		sort(a+1,a+n+1);
		lgg=b[cnt=1]=a[n];
		c[n]=0;
		while (lgg>1 && cnt<n){
			gg=0;
			cnt++;
			for (int i=1; i<=n; i++) if(c[i]){
				tmp1=GCD(lgg,a[i]);
				if (tmp1>gg) gg=tmp1,b[cnt]=a[i],tmp2=i;
			}
			c[tmp2]=0;
			lgg=gg;
		}
		for (int i=1; i<=n; i++) if (c[i]) b[++cnt]=a[i];
		for (int i=1; i<=n; i++) printf("%d ",b[i]);
		
		printf("\n");
		for (int i=1; i<=n; i++) b[i]=0;
	}
}
