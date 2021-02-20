#include <cstdio>
//f[i][j][k]	: s[1..i] 能否删，删的东西还缺 k 个右括号匹配，成 t[1..j] 
bool f[205][205][205];
char s[205],t[205];
int n,m;

int main()
{
	char ch;
	for (ch=getchar(); ch!='(' && ch!=')'; ch=getchar())
		;
	for (n=0; ch=='(' || ch==')'; ch=getchar())
		s[++n]=ch;
	for (; ch!='(' && ch!=')'; ch=getchar())
		;
	for (m=0; ch=='(' || ch==')'; ch=getchar())
		t[++m]=ch;
	
	f[0][0][0]=1;
	
	for (int i=1; i<=n; i++) {
		for (int j=0; j<=m; j++) {
			for (int k=0; k<=i; k++) {
				
				if (s[i]=='(' && k>0) {
					f[i][j][k]|=f[i-1][j][k-1];
				}
				if (s[i]==')') {
					f[i][j][k]|=f[i-1][j][k+1];
				}
				if (s[i]==t[j]) {
					f[i][j][k]|=f[i-1][j-1][k];
				}
				
			}
		}
	}
	
	printf(f[n][m][0] ? "Possible" : "Impossible");
	return 0;
}
/*
(()))()
(()))

(()()())
((()))

((())((())())())
(()(())())
*/
