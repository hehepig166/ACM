#include <bits/stdc++.h>
using namespace std;
int T,ans,n,i,GG,f[200],a[200];

int main(){
	cin >>T;
	while (T--){
		ans=0;
		cin >>n;
		memset(f,0,sizeof(f));
		for (i=1; i<=n; i++){
			cin >>a[i];
			f[a[i]]++;
		}
		for (i=0,GG=0; !GG; i++){
			if (f[i]){f[i]--; continue;}
			if (!f[i]) ans+=i,GG=1;
		}
		for (i=0,GG=0; !GG; i++){
			if (f[i]){f[i]--; continue;}
			if (!f[i]) ans+=i,GG=1;
		}
		cout <<ans <<"\n";
	}
}
