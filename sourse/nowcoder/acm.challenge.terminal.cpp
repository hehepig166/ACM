#include <cstdio>

int main()
{
    long long n,m,ans;
    scanf("%lld%lld",&n,&m);
    ans=n;
    for (int i=2; i<=m; i++)
        ans=ans*(n-1)%1000000000;
    printf("%lld\n",ans);
    return 0;
}
