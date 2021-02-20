//https://vjudge.net/problem/POJ-1417#author=SCU2018
#include <cstdio>
#include <vector>
using namespace std;
#define N 305

vector<int> cnt[305][2];	//统计最终并查集的信息 
int dp[305][305];
int ans[305][305];

int n,p,q,a,b,d,fa,fb,F,fail;
int c[2];
char s[10];
int f[N];
int g[N];
bool vis[N];
int Fa(int x)
{
	if (f[x]!=x) {
		int tmp=f[x];
		f[x]=Fa(tmp);
		g[x]=(g[tmp]+g[x])%2;
	}
	return f[x];
}

void init()
{
	for (int i=1; i<=300; i++) {
		f[i]=i;
		g[i]=0;
		vis[i]=0;
		cnt[i][0].clear();
		cnt[i][0].emplace_back(0);
		cnt[i][1].clear();
		cnt[i][1].emplace_back(0);
	}
}

int main()
{
	while (scanf("%d%d%d",&n,&p,&q)) {
		if (n==0 && p==0 && q==0) {
			break;
		}
		init();
		fail=0;
		while (n--) {
			scanf("%d%d%s",&a,&b,&s);
			
			if (!fail) {
				d=(s[0]=='n');
				
				fa=Fa(a);
				fb=Fa(b);
				vis[a]=vis[b]=1;
				
				if (fa==fb) {
					if ((g[a]-g[b])%2!=d) {
						fail=1;
					}
				}
				else {
					f[fa]=fb;
					g[fa]=(d+g[b]-g[a])%2;
				}
			}
			
			if (fail) {
				puts("no");
				continue;
			}
			
		}
		
		for (int i=1; i<=300; i++) {
			cnt[Fa(i)][g[i]][0]++;
			cnt[Fa(i)][g[i]].emplace_back(i);
		}
		
	}
	return 0;
}
