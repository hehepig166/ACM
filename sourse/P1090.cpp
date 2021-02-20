#include <cstdio>
#include <algorithm>
#include <cmath>
#include <cstring>
using namespace std;
int n,ans;

struct xgd{
	int s[500005],cnt;
	void reset(){
		memset(s,0x7f,sizeof(s));
		cnt=0;
	}
	void add(int x){
		cnt++;
		s[cnt]=x;
		int k=cnt;
		while (k>1 && s[k>>1]>x){
			swap(s[k>>1],s[k]);
			k>>=1;
		}
	}
	void pop(){
		s[1]=s[cnt];
		s[cnt]=2147483647;
		cnt--;
		int k=1;
		while (s[k]>s[k<<1] || s[k]>s[(k<<1)+1]){
			if (s[k]>s[k<<1] && s[k<<1]<s[(k<<1)+1]){
				swap(s[k],s[k<<1]);
				k=k<<1;
			}
			else{
				swap(s[k],s[(k<<1)+1]);
				k=(k<<1)+1;
			}
		}
	}
}A;

int main(){
	scanf("%d",&n);
	A.reset();
	for (int i=1,k; i<=n; i++){
		scanf("%d",&k);
		A.add(k);
	}
	for (int i=1,tmp; i<n; i++){
		tmp=A.s[1];
		A.pop();
		tmp+=A.s[1];
		A.pop();
		A.add(tmp);
		ans+=tmp;
	}
	printf("%d",ans);
}
