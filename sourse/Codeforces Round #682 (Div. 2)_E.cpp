#include<bits/stdc++.h>
#define N 1200000
#define db double
#define ll long long
#define ldb long double
#define ull unsigned long long
using namespace std;
const ll h=3,ki=149,mo=998244353;
ll mod(ll x){return (x%mo+mo)%mo;}
ll inc(ll x,ll k){x+=k;return x<mo?x:x-mo;}
ll dec(ll x,ll k){x-=k;return x>=0?x:x+mo;}
ll ksm(ll x,ll k)
{
	ll ans=1;
	while(k){if(k&1)ans=1ll*ans*x%mo;k>>=1;x=1ll*x*x%mo;}
	return ans;
}
ll inv(ll x){return ksm(mod(x),mo-2);}
ll read()
{
	char ch=0;ll x=0,flag=1;
	while(!isdigit(ch)){ch=getchar();if(ch=='-')flag=-1;}
	while(isdigit(ch)){x=(x<<3)+(x<<1)+ch-'0',ch=getchar();}
	return x*flag;
}
void write(ll x)
{
	if(!x)return (void)putchar(48);
	if(x<0)putchar(45),x=-x;
	ll len=0,p[20];
	while(x)p[++len]=x%10,x/=10;
	for(ll i=len;i>=1;i--)putchar(p[i]+48);
}
const db eps=1e-7,inf=1e9+7,pi=acos(-1);
db Read(){db x;scanf("%lf",&x);return x;}
void Write(db x){printf("%lf",x);}
ll a[N],s[N],p[N];
bool cmp(ll x,ll y){return a[x]>a[y];}
int main()
{
	ll n=read(),ans=0;
	for(ll i=1;i<=n;i++)a[i]=read(),s[i]=s[i-1]+a[i],p[i]=i;
	for(ll k=3;k<=200;k++)
	{
		
		for(ll i=1;i+k-1<=n;i++)
		{
			ll l=i,r=i+k-1;
			if((a[l]^a[r])==s[r-1]-s[l])ans++;
		}
	}
	sort(p+1,p+n+1,cmp);
	for(ll k=1;k<=min(200ll,n);k++)
	{
		ll l=p[k];
		for(ll r=l+200;r<=n;r++)if((a[l]^a[r])==s[r-1]-s[l])ans++;
	}
	for(ll k=1;k<=min(200ll,n);k++)
	{
		ll r=p[k];
		for(ll l=1;l<=r-200;l++)if((a[l]^a[r])==s[r-1]-s[l])ans++;
	}
	
	write(ans);
	return 0;
}

