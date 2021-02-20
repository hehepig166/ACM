#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;
typedef long long ll;
const ll mod=1e9+7;

ll fpow(ll a,ll n,ll mod)
{
    ll sum=1,base=a%mod;
    while(n!=0)
    {
        if(n%2)sum=sum*base%mod;
        base=base*base%mod;
        n/=2;
    }
    return sum;
}

ll ex_gcd(ll a,ll b,ll& x,ll& y)
{
    if(b==0)
    {
        x=1;y=0;
        return a;
    }
    ll ans=ex_gcd(b,a%b,x,y);
    ll tmp=x;
    x=y;
    y=tmp-a/b*y;
    return ans;
}

ll inv(ll a,ll mod)//存在逆元条件：gcd(a,mod)=1
{
    ll x,y;
    ll g=ex_gcd(a,mod,x,y);
    if(g!=1)return -1;
    return (x%mod+mod)%mod;
}

ll gcd(ll a,ll b)
{
    return b?gcd(b,a%b):a;
}

ll BSGS(ll a,ll b,ll p)
{
    b%=p;
    if(b==1||p==1)return 0;
    ll n=sqrt(p);
    static unordered_map<ll,ll>Bmp;
    Bmp.clear();
    ll inva=inv(fpow(a,n-1,p),p)*b%p;
    for(ll i=n-1;i>=0;i--)
    {
        Bmp[inva]=i;inva=inva*a%p;
    }
    ll ta=1,powa=fpow(a,n,p);
    for(ll k=0;k<=p;k+=n)
    {
        if(Bmp.count(ta))return k+Bmp[ta];
        ta=ta*powa%p;
    }
    return -1;
}

ll exBSGS(ll a,ll b,ll p)
{
    b%=p;
    if(a==0&&b==0)return 1;
    else if(a==0&&b!=0)return -1;
    if(b==1||p==1)return 0;
    ll d=gcd(a,p);
    if(b%d!=0)return -1;
    p=p/d;
    b=b/d*inv(a/d,p)%p;
    if(d!=1)
    {
        ll ans=exBSGS(a,b,p);
        if(ans==-1)return -1;
        return ans+1;
    }
    ll ans=BSGS(a,b,p);
    if(ans==-1)return -1;
    return ans+1;
}

int main()
{
    ll a=10,p,b;
    scanf("%d",&T);
    while (T--){
    	scanf("%d",&n);
    	p=n,b=n-1;
        ll ans=exBSGS(a,b,p);
        printf("%lld\n",ans);
	}
    return 0;
}
