#include <cstdio>
#include <queue>
using namespace std;
priority_queue < int , vector<int> , greater<int> > q;
int n,a[200005],b[200005],c[200005],f[200005];
char ch;

int main()
{
	scanf("%d",&n);
	for (int i=1,j=(n<<1); i<=j; i++)
	{
		c[i]=f[i]=0;
		for (ch=getchar(); ch!='-' && ch!='+'; ch=getchar())
			continue;
		a[i]=ch;
		if (ch=='-')
			scanf("%d",&b[i]);
	}
	
	for (int i=(n<<1); i; i--)
	{
		if (a[i]=='-')
		{
			if (q.size()>0 && b[i]>q.top())
			{
				printf("NO\n");
				return 0;
			}
			q.push(b[i]);
			f[b[i]]=1;
		}
		else
		{
			if (q.empty())
			{
				printf("NO\n");
				return 0;
			}
			c[i]=q.top();
			f[c[i]]=0;
			q.pop();
		}
	}
	
	printf("YES\n");
	for (int i=1,j=(n<<1); i<=j; i++)
		if (c[i])
			printf("%d ",c[i]);
	
	return 0;
}
