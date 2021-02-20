#include <cstdio>
#include <algorithm>
using namespace std;
int n,s,a,b,x,y,cnt,c[10000];

int main(){
	scanf("%d%d%d%d",&n,&s,&a,&b);
	for (int i=1; i<=n; i++){
		scanf("%d%d",&x,&y);
		if (x<=a+b) c[++cnt]=y;
	}
	sort(c+1,c+cnt+1);
	for (int i=1; i<=cnt; i++){
		if (s>=c[i]){
			s-=c[i];
			continue;
		}
		printf("%d",i-1);
		return 0;
	}
	printf("%d",cnt);
}
