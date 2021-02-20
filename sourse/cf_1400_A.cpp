//https://codeforces.com/contest/1400/problem/0
#include <cstdio>
int a[10000],t,n,num,cnt,he;
char ch,lst;

void rd(char &xx){
	xx='4';
	while (xx!='1'&&xx!='0') scanf("%c",&xx);
}

int main(){
	scanf("%d",&t);
	for (; t--; ){
		scanf("%d",&n);
		cnt=0,he=0;
		for (int i=1,j=2*n-1; i<=j; i++){
			rd(ch);
			if (ch==lst) cnt++; else lst=ch,cnt=1;
			if (cnt==n) he=ch-'0';
		}
		for (int i=1; i<=n; i++) printf("%d",he);
		printf("\n");
	}
}
