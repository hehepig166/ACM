#include <bits/stdc++.h>
using namespace std;
int T,n,cnt1,cnt2,cnt3,tmp;
long long a1[100005],a2[100005],b1[100005],b2[100005],b3[100005],ans;

bool cmp(int x,int y){return x>y;}

int main(){
	cin >>T;
	while (T--){
		memset(a1,0,sizeof(a1));
		memset(a2,0,sizeof(a2));
		cin >>n;
		cnt1=cnt2=cnt3=0;
		for (int i=1,tmp; i<=n; i++){
			cin >>tmp;
			if (tmp<0) a1[++cnt1]=tmp;
			if (tmp>0) a2[++cnt2]=tmp;
			if (tmp==0) cnt3++;
		}
		if (cnt3>n-5){
			cout <<"0\n";
			continue;
		}
		sort(a1+1,a1+cnt1+1,cmp);
		sort(a2+1,a2+cnt2+1,cmp);
		b1[0]=b2[0]=b3[0]=1;
		for (int i=1; i<=5; i++) if (i<=cnt1) b1[i]=b1[i-1]*a1[i];
		for (int i=cnt1,k=1; k<=5 && i; i--,k++) b3[k]=b3[k-1]*a1[i];
		b2[0]=1;
		for (int i=1; i<=5; i++) if (i<=cnt2) b2[i]=b2[i-1]*a2[i];
		ans=-300000000000000000ll;
		if (cnt3) ans=0;
		for (int i=0; i<=5; i++) if (cnt1>=i && cnt2>=5-i){
			ans=max(ans,b1[i]*b2[5-i]);
			ans=max(ans,b3[i]*b2[5-i]);
		}
		cout <<ans <<"\n";
	}
}
