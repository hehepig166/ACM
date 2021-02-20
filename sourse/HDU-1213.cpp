//https://vjudge.net/problem/HDU-1213
#include <cstdio>
#include <iostream>
using namespace std;

short int f[1000],T,n,m,u,v,fu,fv;
inline int Fa(int x) {
	return f[x]==x ? x : f[x]=Fa(f[x]);
}

int main()
{
	cin >>T;
	while (T--) {
		cin >>n >>m;
		for (int i=0; i<n; i++) {
			f[i]=i;
		}
		while (m--) {
			cin >>u >>v;
			u--,v--;
			fu=Fa(u);
			fv=Fa(v);
			if (fu<fv) {
				swap(fu,fv);
			}
			if (fu!=fv) {
				n--;
				f[fu]=fv;
			}
		}
		cout <<n <<endl;
	}
	return 0;
}
