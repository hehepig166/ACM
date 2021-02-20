#include <cstdio>
#include <string>
#include <cstream>
using namespace std;

int main(){
	scanf("%d",&n);
	for (int i=1; i<=n; i++){
		cin >>a[i];
		b[a[i][0]-'a'][++c[a[i][0]-'a']]=a[i];
	}
	for (int i=0; i<26; i++) sort(b[i]+1,b[i]+c[i]+1);
}
