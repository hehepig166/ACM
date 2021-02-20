#include <cstdio>
#include <map>
using namespace std;
map<int, int> mp;
int L,Q,cnt,l[5005],r[5005],DD[5005],f[10005],v[10005];

int Fa(int x)
{
	if (f[x]==x)
	{
		return x;
	}
	int tmp=f[x];
	f[x]=Fa(tmp);
	v[x]=(v[x]+v[tmp]+2)%2;
	return f[x];
}

int main()
{
	char s[8];
	int fail,a,b,D,fa,fb;
	
	while (scanf("%d",&L)==1)
	{
		scanf("%d",&Q);
		
		mp.clear();
		cnt=0;
		
		fail=Q;
				
		for (int i=1; i<=Q; i++)
		{
			scanf("%d%d%s",&l[i],&r[i],s);			
			DD[i]=(s[0]=='o');
			l[i]--;
			if (!mp[l[i]])
				mp[l[i]]=++cnt;
			if (!mp[r[i]])
				mp[r[i]]=++cnt;
		}
		
		for (int i=1; i<=cnt; i++)
		{
			f[i]=i;
			v[i]=0;
		}
		
		for (int i=1; i<=Q; i++)
		{
			a=mp[l[i]];
			b=mp[r[i]];
			
			fa=Fa(a);
			fb=Fa(b);
			
			D=DD[i];
			
			if (fa==fb)
			{
				if ((v[a]-v[b]+2)%2!=D)
				{
					fail=i-1;
					break;
				}
			}
			else
			{
				v[fa]=(D-v[a]+v[b]+2)%2;
				f[fa]=fb;
			}
		}
		
		printf("%d\n",fail);
		
	}
	return 0;
}
