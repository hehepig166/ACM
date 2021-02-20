//https://vjudge.net/problem/HDU-3038
#include <cstdio>

//�赱ǰ�ڵ�Ϊ x 
//f: ָ��ĸ��ڵ� (f>x) 
//s: ���� (x,f] �ĺ� (���ұ�) 
int f[200005],s[200005];
int n,m,a,b,fa,fb,z,ans;

int Fa(int x)
{
	if (f[x]!=x) {
		int tmp=f[x];
		f[x]=Fa(tmp);	//��ѹ���ø��ڵ��·����ά������ s[] ֵ����ܼ��㵱ǰ�ڵ�� s[] ֵ 
		s[x]+=s[tmp];
	}
	return f[x];
}

void init() {
	ans=0;
	for (int i=0; i<=n; i++) {	//ע��� 0 ��ʼ����Ϊ�����䣬���õ� 0 
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
				ans+=(s[a]-s[b]!=z);	//�ж��Ƿ�ʧ�� 
			}
			else {
				f[fa]=fb;
				s[fa]=z+s[b]-s[a];	//�����Ӽ��õ� 
			}
		}
		
		printf("%d\n",ans);
	}
	return 0;
}
