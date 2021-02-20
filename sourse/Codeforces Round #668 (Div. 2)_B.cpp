#include <cstdio>
int n,t,a[500000],l,r,tmp;
long long ans;

int main(){
	scanf("%d",&t);
	while (t--){
		ans=0;
		scanf("%d",&n);
		for (int i=1; i<=n; i++) scanf("%d",&a[i]);
		for (r=1; a[r]>0; r++);
		for (l=1; l<=n; l++){
			if (a[l]<0) continue;
			if (r<=l) r=l+1;
			for (; r<=n; r++){
				if (a[r]>0) continue;
				if (a[l]+a[r]<=0){a[r]+=a[l],a[l]=0; break;}
				if (a[l]+a[r]>0) a[l]+=a[r],a[r]=0; 
			}
		}
		for (int i=1; i<=n; i++) if (a[i]<0) ans-=a[i];
		printf("%lld\n",ans);
	}
}
