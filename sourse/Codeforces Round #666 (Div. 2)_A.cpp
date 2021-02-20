#include <cstdio>
int t,n,f=1,a[30];
void rd(){
	char ch;
	for (scanf("%c",&ch); ch<'a' || ch>'z'; ) scanf("%c",&ch);
	for (; ch>='a' && ch<='z'; ) a[ch-'a']++,scanf("%c",&ch);
}

int main(){
	scanf("%d",&t);
	for (f=1; t; t--,f=1){
		for (int i=0; i<26; i++) a[i]=0;
		scanf("%d",&n);
		for (int i=1; i<=n; i++) rd();
		for (int i=0; i<=25; i++) if (a[i]%n!=0){
			printf("NO\n");
			f=0;
			break;
		}
		if (f) printf("YES\n");
	}
}
