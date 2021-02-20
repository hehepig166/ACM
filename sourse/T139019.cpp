#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#define tr(x,y) (((x)-1)*m+y)
#define Add(x,y) num++,E[num].u=x,E[num].v=y,E[num].nxt=head[x],head[x]=num
#define For(x) for(long long h=head[x],V=E[h].v; h; V=E[h=E[h].nxt].v)
using namespace std;

long long Fx[4][2]={{1,0},{-1,0},{0,1},{0,-1}};
int head[1000005],f[1000005],num,K;
long long n,m,a,b,c,R[1000005],minA[1000005],minB[1000005],minC[1000005],INF;
struct Edge{int u,v,nxt;} E[5000000];
//int q[2000005],l,r;

struct Pri_que
{
	int q[8000005],cnt;
	
	void Push(int x,long long *d)
	{
		q[++cnt]=x;
		int k=cnt;
		while (d[q[k/2]]>d[x] && k>1)
		{ 
			swap(q[k/2],q[k]);
			k=k/2;
		} 
	}
	
	int Pop(long long *d)
	{
		long long ret;
		ret=q[1];
		swap(q[1],q[cnt]);
		q[cnt]=0;
		cnt--;
		int k=1;
		while (d[q[k]]>d[q[k<<1]] || d[q[k]]>d[q[(k<<1)+1]])
		{
			if (d[q[k]]>d[q[k<<1]] && d[q[k<<1]]<d[q[(k<<1)+1]])
			{
				swap(q[k],q[k<<1]);
				k=k<<1;
			}else
			{
				swap(q[k],q[(k<<1)+1]);
				k=(k<<1)+1;
			}
		}
		return ret;
	}
	
}Q;

void Solve(int x,long long *d)
{
	for (int i=0; i<8000005; i++) Q.q[i]=0;
	memset(f,0,sizeof(f));
	for (int i=0; i<=K; i++) d[i]=INF;
	d[x]=R[x];
	Q.cnt=0;
	Q.Push(x,d);
	while (Q.cnt)
	{
		int q=Q.Pop(d);
		if (f[q]) continue;
		f[q]=1;
		
		int tmp=INF;				
		For(q)
			if (d[V]>d[q]+R[V])
			{
				d[V]=d[q]+R[V];
				if (!f[V]) Q.Push(V,d);
			}
	}
}
/*
void SPFA(long long x,long long *d)
{
	for (long long i=1,k=n*m; i<=k; i++)
		d[i]=INF,f[i]=0;
	memset(f,0,sizeof(f));
	memset(q,0,sizeof(q));
	f[x]=1,d[x]=R[x];
	for (q[l=r=0]=x; l<=r; l++)
	{
		For(q[l]) if (d[q[l]]+R[V]<d[V])
		{
			d[V]=d[q[l]]+R[V];
			if (!f[V])
				q[++r]=V,f[V]=1;
		}
		f[q[l]]=0;
	}
}
*/
int main()
{
	scanf("%lld%lld%lld%lld%lld",&n,&m,&a,&b,&c);
	K=n*m;
	for (long long i=1; i<=n; i++)
		for (long long j=1; j<=m; j++)
		{
			scanf("%lld",&R[tr(i,j)]);
			INF+=R[tr(i,j)];
		}
	for (long long i=1,uu,vv,xx,yy; i<=n; i++)
		for (long long j=1; j<=m; j++)
			for (long long fx=0; fx<4; fx++)
			{
				xx=i+Fx[fx][0];
				yy=j+Fx[fx][1];
				if (xx<=0 || xx>n || yy<=0 || yy>m) continue;
				uu=tr(i,j);
				vv=tr(xx,yy);
				Add(uu,vv);
			}
	
	Solve(tr(1,a),minA);
	Solve(tr(n,b),minB);
	Solve(tr(n,c),minC);
	
	int ansl;
	
	for (long long i=1,s; i<=K; i++)
	{
		s=minA[i]+minB[i]+minC[i]-R[i]-R[i];
		if (s<INF) INF=s,ansl=i;
	}
	printf("%lld",INF);
	
	
	return 0;
}

	/*
	
	for (long long i=1; i<=n; i++)
	{
		printf("\n");
		for (long long j=1; j<=m; j++)
			printf("%d ",minA[tr(i,j)]);
	}
	printf("\n");
	for (long long i=1; i<=n; i++)
	{
		printf("\n");
		for (long long j=1; j<=m; j++)
			printf("%d ",minB[tr(i,j)]);
	}
	printf("\n");
	for (long long i=1; i<=n; i++)
	{
		printf("\n");
		for (long long j=1; j<=m; j++)
			printf("%d ",minC[tr(i,j)]);
	}
	
	*/
