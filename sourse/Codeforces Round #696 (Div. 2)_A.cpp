#include <cstdio>
#include <cstring>
using namespace std;

int T,n,tmp;
char b[100005],a[100005];

int main()
{
	scanf("%d",&T);
	while (T--) {
		scanf("%d%s",&n,b);
		tmp=0;
		for (int i=0; i<n; i++) {
			if (tmp!=2 && b[i]=='1') {
				tmp=2;
				a[i]='1';
				continue;
			}
			if (tmp!=1) {
				tmp=1;
				a[i]=((b[i]-'0')^1)+'0';
				continue;
			}
			a[i]='0';
			tmp=b[i]-'0';
		}
		a[n]=0;
		printf("%s\n",a);
	}
	return 0;
}
