#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;

int Ans=0;
int n,m;
int graph[1005][1005]={0};
int deg[1005]={0};
int f[1005],a[1005];

int main()
{

	
	scanf("%d%d",&n,&m);
	for (int i=1,s; i<=m; i++) {
		scanf("%d",&s);
		memset(a,0,sizeof(a));
		memset(f,0,sizeof(f));
		for (int i=1; i<=s; i++) {
			scanf("%d",&a[i]);
			f[a[i]]=1;
		}
		for (int j=1; j<s; j++) {
			for (int k=a[j]+1; k<a[s]; k++) {
				if (!f[k]) {
					graph[a[j]][k]=1;
					deg[a[j]]++;
				}
			}
		}
	}
	
	for (int cnt=n; cnt; ) {
		for (int i=1; i<=n; i++) {
			if (deg[i]==0) {
				deg[i]=-1;
				for (int j=1; j<=n; j++) {
					if (graph[i][j]) {
						graph[i][j]=0;
					}
				}
				cnt--;
			}
		}
		Ans++;
	}
	
	printf("%d\n",Ans);
	return 0;
}
/*
9 2 
4 1 3 5 6 
3 3 5 6 
*/
