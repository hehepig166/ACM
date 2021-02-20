#include <cstdio>
int n,a[50];
// f[i][j] 前 i 个平均值小于等于 j 的序列个数。
int f[50][50];

int main()
{
    scanf("%d",&n);
    for (int i=1; i<=n; ++i) {
        scanf("%d",&a[i]);
    }

    f[0][0]=1;

    for (int i=1; i<=n; i++) {
        for (int j=0; j<=40; j++) {
            
        }
    }


}