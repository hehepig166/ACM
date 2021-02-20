#include <cstdio>
#define N 200005

int T,n,m,L,R,Max,Min;
char ch[N];
int x1[N],x2[N],max1[N],max2[N],min1[N],min2[N];

int max(int x,int y) {return x>y ? x : y;}
int min(int x,int y) {return x<y ? x : y;}

int main()
{
	scanf("%d",&T);
	while (T--) {
		scanf("%d%d%s",&n,&m,(ch+1));
		x1[0]=x2[n+1]=max1[0]=max2[n+1]=min1[0]=min2[n+1]=0;
		
		for (int i=1; i<=n; i++) {
			x1[i]=x1[i-1]+(ch[i]=='-' ? -1 : 1);
			max1[i]=max(max1[i-1],x1[i]);
			min1[i]=min(min1[i-1],x1[i]);
		}
		for (int i=n; i; i--) {
			x2[i]=x2[i+1]+(ch[i]=='-' ? 1 : -1);
			max2[i]=max(max2[i+1],x2[i]);
			min2[i]=min(min2[i+1],x2[i]);
		}
		
		while (m--) {
			scanf("%d%d",&L,&R);
			Max=max(max1[L-1],max2[R+1]+x1[L-1]-x2[R+1]);
			Min=min(min1[L-1],min2[R+1]+x1[L-1]-x2[R+1]);
			printf("%d\n",Max-Min+1);
		}
	}
	return 0;
}
