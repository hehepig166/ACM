#include <cstdio>
#include <algorithm>
#include <cstring> 
using namespace std;

struct big_number{
	int s[1000],cnt;
	big_number operator + (big_number b){
		big_number ret={0};
		for (int i=1,k=max(cnt,b.cnt); i<=k; i++){
			ret.s[i]+=s[i]+b.s[i];
			ret.s[i+1]+=ret.s[i]/10;
			ret.s[i]%=10;
			ret.cnt=max(ret.cnt,i);
		}
		ret.cnt+=(ret.s[ret.cnt+1]>0);
		return ret;
	}
	big_number operator + (int b){
		s[1]+=b;
		
	}
	big_number operator * (big_number b){
		big_number ret={0};
		for (int i=1; i<=cnt; i++){
			for (int j=1; j<=b.cnt; j++){
				ret.s[i+j-1]+=s[i]*b.s[j];
				ret.s[i+j]+=ret.s[i+j-1]/10;
				ret.s[i+j-1]%=10;
				ret.cnt=max(i+j-1,ret.cnt);
			}
		}
		ret.cnt+=(ret.s[ret.cnt+1]>0);
		return ret;
	}
	void rd(){
		char b[1000];
		scanf("%s",b);
		cnt=strlen(b);
		for (int i=1; i<=cnt; i++) s[i]=b[cnt-i]-'0';
	}
	void pt(){
		for (int i=cnt; i; i--) printf("%d",s[i]);
		puts("");
	}
} x,y,z,p,q;

int main(){
	//f[i]=(f[i-1]*3-f[i-2]+2)
	scanf("%d",&n);
	p.cnt=1,p.s[1]=2;
	q.cnt=1,q.s[1]=3;
	for (int i=1; i<=n; i++){
		x=y*q-z+p;
	}
}
