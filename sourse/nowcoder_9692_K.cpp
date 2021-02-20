#include <cstdio>
int n,q,a[200],x,y,opr,cnt;

int main()
{
	scanf("%d%d",&n,&q);
	for (int i=1; i<=n; i++)
		scanf("%d",&a[i]);
	while (q--)
	{
		scanf("%d",&opr);
		if (opr==1)
		{
			scanf("%d",&x);
			for (int i=x; i<n; i++)
				a[i]=a[i+1];
			
			n--;
			for (int i=1; i<=n; i++)
				printf("%d ",a[i]);
			printf("\n");
			continue;
		}
		else if (opr==2)
		{
			scanf("%d%d",&x,&y);
			for (int i=n; i>=x; i--)
				a[i+1]=a[i];
			a[x]=y;
			
			n++;
			for (int i=1; i<=n; i++)
				printf("%d ",a[i]);
			printf("\n");
			continue;
		}
		else if (opr==3)
		{
			scanf("%d",&x);
			for (cnt=0; x+cnt<=n && a[x+cnt]==a[x]; cnt++)
				continue;
			
			a[x]=cnt*a[x];
			
			cnt--;
			
			for (int i=x+1,j=n-cnt; i<=j; i++)
				a[i]=a[i+cnt];
			
			n-=cnt;
			for (int i=1; i<=n; i++)
				printf("%d ",a[i]);
			printf("\n");
			continue;
		}
	}
	return 0;
}
