#include <cstdio>
int t,n,k,cnt[3],a[5000000];

int du(){
	char ch;
	scanf("%c",&ch);
	while (ch!='0' && ch!='1' && ch!='?') scanf("%c",&ch);
	if (ch=='?') return -1;
	return ch-'0';
}

int main(){
	scanf("%d",&t);
	for (int f=1; t; t--,f=1){
		scanf("%d%d",&n,&k);
		cnt[1]=cnt[0]=0;
		for (int i=1; i<=n; i++) a[i]=du();
		for (int i=1,j=n-k; i<=j && f; i++){
			if (a[i]!=a[i+k] && a[i]!=-1 && a[i+k]!=-1) f=0;
			if (f && a[i]!=-1) a[i+k]=a[i];
		}
		for (int i=1,j=n-k; i<=j && f; i++)
			if (a[i]!=a[i+k] && a[i]!=-1 && a[i+k]!=-1) f=0;
		for (int i=1; i<=k; i++) if (a[i]>=0) cnt[a[i]]++;
		if (cnt[0]>k/2 || cnt[1]>k/2) f=0;
		for (int i=k+1; i<=n && f; i++){
			if (a[i]>=0) cnt[a[i]]++;
			if (a[i-k]>=0) cnt[a[i]]--;
			if (cnt[0]>k/2 || cnt[1]>k/2) f=0;
		}
		if (f) printf("YES\n");
		else printf("NO\n");
	}
}
