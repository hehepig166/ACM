//https://vjudge.net/problem/HDU-3038
#include <cstdio>

//设当前节点为 x 
//f: 指向的父节点 (f>x) 
//s: 区间 (x,f] 的和 (左开右闭) 
int f[200005],s[200005];
int n,m,a,b,fa,fb,z,ans;

int Fa(int x)
{
	if (f[x]!=x) {
		int tmp=f[x];
		f[x]=Fa(tmp);	//先压缩好父节点的路径，维护好其 s[] 值后才能计算当前节点的 s[] 值 
		s[x]+=s[tmp];
	}
	return f[x];
}

void init() {
	ans=0;
	for (int i=0; i<=n; i++) {	//注意从 0 开始，因为开区间，会用到 0 
		f[i]=i;
		s[i]=0;
	}
}

int main()
{
	while (scanf("%d%d",&n,&m)!=EOF) {
		
		init();
	
		while (m--) {
			scanf("%d%d%d",&a,&b,&z);
			a--;
			fa=Fa(a);
			fb=Fa(b);
			
			if (fa==fb) {
				ans+=(s[a]-s[b]!=z);	//判断是否失败 
			}
			else {
				f[fa]=fb;
				s[fa]=z+s[b]-s[a];	//向量加减得到 
			}
		}
		
		printf("%d\n",ans);
	}
	return 0;
}
