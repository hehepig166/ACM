#include <cstdio>
int a[300],l[300],r[300],cnt,K;

void he(int x){
	if (x<1 || x>cnt) return;
	if (!K) return;
	if (a[x]>=a[l[x]] && a[x]>a[r[x]]){
		l[r[x]]=l[x];
		r[l[x]]=r[x];
		a[x]=-1;
		K--;
		he(l[x]);
		he(r[x]);
	}
}
 
int main(){
	char ch=getchar();
	while (ch<'0' || ch>'9') ch=getchar();
	while (ch>='0' && ch<='9') a[++cnt]=ch-'0',ch=getchar();
	for (int i=1; i<=cnt; i++) l[i]=i-1,r[i]=i+1;
	scanf("%d",&K);
	for (int i=1; i<=cnt; i++) he(i);
	int ff=0;
	for (int i=1; i<=cnt; i++) if (a[i]>=0){
		if (ff){
			printf("%d",a[i]);
			continue;
		}
		if (a[i]==0) continue;
		printf("%d",a[i]);
		ff=1;
	}
	if (!ff) printf("0");
}
