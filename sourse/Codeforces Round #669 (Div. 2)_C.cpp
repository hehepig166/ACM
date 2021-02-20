#include <cstdio>
int n,mx,x,y,p[20000];

int main(){
	scanf("%d",&n);
	mx=1;
	for (int i=2; i<=n; i++){
		printf("? %d %d\n",mx,i);
		fflush(stdout);
		scanf("%d",&x);
		printf("? %d %d\n",i,mx);
		fflush(stdout);
		scanf("%d",&y);
		if (x<y){
			p[i]=y;
		}
		else{
			p[mx]=x;
			mx=i;
		}
	}
	p[mx]=n;
	printf("! ");
		for (int i=1; i<=n; i++) printf("%d ",p[i]);
}
