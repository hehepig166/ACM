#include <cstdio>
int T,k;
long long K,tmp,n;

int he(long long x){
		tmp=x%K;
		x/=K;
		x-=tmp;
		if (x<0) x=-x;
		if (x%n!=0) return 0;
	return 1;
}

int main(){
	scanf("%d",&T);
	while (T--){
		scanf("%lld",&n);
		if (n==1){
			printf("0\n");
			continue;
		}
		if (n%2==0) {
			printf("-1\n");
			continue;
		}
		for (k=1,K=10; k<=9999999; k++,K*=10){
			while(K>=n) K%=n;
			if (K==0){printf("-1\n"); break;}
			if (K==n-1){printf("%d\n",k); break;}
		}
		if (k==10000000) printf("-1\n");
		/*
		for (k=1,K=10; k<=50; k++,K*=10)
			if (he(n*666233452547541ll) && he(n*32456423215364ll) && he(n*214748362447ll) && he(n*111111111111111ll) && he(n*615512355556) && he(n*115764522147) && he(n*11451448643) && he(n*1260647889)) break;
		if (k>=51){printf("-1\n"); continue;}
		printf("%d\n",k);
		*/
	}
}
