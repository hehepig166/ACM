#include <cstdio>
int t,n,a[5000],c[5000];

int du(){
	int ret=0;
	char ch=getchar();
	while (ch<'0' || ch>'9') ch=getchar();
	for (; ch>='0' && ch<='9'; ch=getchar()) ret=(ret<<3)+(ret<<1)+ch-'0';
	return ret;
}

int main(){
	scanf("%d",&t);
	while (t--){
		c[0]=c[1]=0;
		scanf("%d",&n);
		for (int i=1; i<=n; i++){
			scanf("%d",&a[i]);
			c[a[i]]++;
		}
		if (c[0]>=n/2){
			printf("%d\n",c[0]);
			for (int i=1; i<=c[0]; i++) printf("0 ");
			printf("\n");
		}
		if (c[1]>n/2){
			if (c[1]%2) c[1]--;
			printf("%d\n",c[1]);
			for (int i=1; i<=c[1]; i++) printf("1 ");
			printf("\n");
		}
	}
}
