#include <bits/stdc++.h>
using namespace std;
   
typedef long long LL;
const int N=60;
 
LL dp[100005];
 
struct Node
{
	LL point,minute,time;
	friend bool operator<(const Node& a,const Node& b)
	{
		return a.time*a.minute+(a.time+b.time)*b.minute<b.time*b.minute+(b.time+a.time)*a.minute;
	}
}a[N];
 
int main()
{
	int n,t;
	
	memset(dp,0,sizeof(dp));
    
	scanf("%d%d",&n,&t);

	for(int i=1;i<=n;i++)
        scanf("%d",&a[i].point);
    for(int i=1;i<=n;i++)
        scanf("%d",&a[i].minute);
    for(int i=1;i<=n;i++)
        scanf("%d",&a[i].time);
    
	sort(a+1,a+1+n);
  
	LL ans=0;
	for(int i=1;i<=n;i++)
		for(int j=t;j>=a[i].time;j--)
		{
			dp[j]=max(dp[j],dp[j-a[i].time]+a[i].point-a[i].minute*j);
			ans=max(ans,dp[j]);
		}
	printf("%lld\n",ans);
    return 0;
}