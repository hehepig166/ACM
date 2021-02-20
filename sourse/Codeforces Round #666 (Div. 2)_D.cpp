#include <cstdio>
#include <algorithm>
using namespace std;
int t,n,a[200],S,T,HL;

int main(){
	scanf("%d",&t);
	while (t--){
		T=HL=0;
		scanf("%d",&n);
		for (int i=1; i<=n; i++) scanf("%d",&a[i]);
		sort(a+1,a+n+1);
		S=0;
		for (int i=1; i<n; i++) S+=a[i];
		if (S<a[n]){
			printf("T\n");
			continue;
		}
		S+=a[n];
		if (S%2) printf("T\n");
		else printf("HL\n");
		for (int i=1; i<=n; i++){
			if (i%2) T+=a[n-i+1];
			else HL+=a[n-i+1];
		}
		//if (T>HL) printf("T\n");
		//else printf("HL\n");
	}
} 
