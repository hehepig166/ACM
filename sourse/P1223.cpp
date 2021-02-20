#include <cstdio>
#include <algorithm>
using namespace std;
int n,T,a[100000],b[10000];
double ans;

bool cmp(int x,int y){return a[x]<a[y];}

int main(){
	scanf("%d",&n);
	for (int i=1; i<=n; i++) scanf("%d",&a[i]),b[i]=i;
	sort(b+1,b+n+1,cmp);
	for (int i=1; i<=n; i++){
		printf("%d ",b[i]);
		T+=a[b[i-1]];
		ans+=T;
	}
	ans=ans/n;
	printf("\n%.2lf",ans);
} 
