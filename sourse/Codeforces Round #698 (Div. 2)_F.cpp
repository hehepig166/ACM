#include <bits/stdc++.h>
using namespace std;
long long n,X[5005],Y[5005],tmp,tmpd,nowp;
bool f[5005];

long long dis(int x, int y)
{
	return (X[x]-X[y])*(X[x]-X[y])+(Y[x]-Y[y])*(Y[x]-Y[y]);
}

int main()
{
	scanf("%lld",&n);
	for (int i=1; i<=n; i++) {
		scanf("%lld%lld",&X[i],&Y[i]);
	}
	
	f[1]=nowp=1;
	printf("1 ");
	for (int i=2; i<=n; i++) {
		tmp=nowp;
		tmpd=-1;
		for (int j=1; j<=n; j++) {
			if (!f[j] && dis(nowp,j)>tmpd) {
				tmp=j;
				tmpd=dis(nowp,tmp);
			}
		}
		f[tmp]=1;
		printf("%lld ",tmp);
		nowp=tmp;
	}
	
	return 0;
}
