#include <cstdio>
#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;

struct edge
{
    int u, v, w;
    edge(){}
    edge(int u, int v, int w) : u(u), v(v), w(w) {}
    bool operator < (const edge &b){return this->w < b.w;}
};

int f[10005],X[10005],Y[10005];
int Fa(int x){return f[x]==x ? x : f[x]=Fa(f[x]);}

void solve()
{
    int n;
    vector<edge> E;
    scanf("%d",&n);
    for (int i=1; i<=n; i++)
    {
        scanf("%d%d",&X[i],&Y[i]);
        for (int j=1; j<i; j++)
            E.push_back(edge(i,j,(X[i]-X[j])*(X[i]-X[j])+(Y[i]-Y[j])*(Y[i]-Y[j])));
    }
    sort(E.begin(),E.end());

    int fu,fv,cnt=n-1;
    double ans=0;
    for (int i=1; i<=n; i++)
        f[i]=i;
    for (auto &e: E) if (e.w>=100 && e.w<=1000000)
    {
        fu=Fa(e.u);
        fv=Fa(e.v);
        if (fu!=fv)
        {
            f[fu]=fv;
            ans+=sqrt(e.w);
            cnt--;
        }
    }

    ans*=100;

    cnt ? printf("oh!\n") : printf("%.1f\n",ans);
}

int main()
{
    int t;
    scanf("%d",&t);
    while (t--)
        solve();
    return 0;
}