//https://vjudge.net/problem/POJ-1611
#include <cstdio>
#define N 30005

int f[N],vis[N];
int Fa(int x) {return f[x]==x ? x : f[x]=Fa(f[x]);}
int n,m,ans,k,u,v,fu,fv,tmp;

int main()
{
	while (1) {
		scanf("%d%d",&n,&m);
		if (n==0 && m==0) {
			break;
		}
		
		for (int i=0; i<n; i++) {
			f[i]=i;
			vis[i]=0;
		}
		
		while (m--) {
			scanf("%d",&k);
			if (k<=0) {
				continue;
			}
			
			scanf("%d",&v);
			fv=Fa(v);
			while (--k) {
				u=v;
				fu=fv;
				
				scanf("%d",&v);
				fv=Fa(v);
				
				if (fu!=fv) {
					ans--;
					f[fu]=fv;
				}
			}
		}
		
		tmp=Fa(0);
		ans=0;
		for (int i=0; i<n; i++)
			ans+=(Fa(i)==tmp);
		
		printf("%d\n",ans);
		
	}
	return 0;
}
