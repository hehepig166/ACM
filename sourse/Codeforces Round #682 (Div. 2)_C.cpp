#include<bits/stdc++.h>
#define M 1100
#define N 550000
#define db double
#define ll long long
#define ldb long double
#define ull unsigned long long
using namespace std;
const int h=3,ki=149,mo=998244353;
int mod(int x){return (x%mo+mo)%mo;}
int inc(int x,int k){x+=k;return x<mo?x:x-mo;}
int dec(int x,int k){x-=k;return x>=0?x:x+mo;}
int ksm(int x,int k)
{
	int ans=1;
	while(k){if(k&1)ans=1ll*ans*x%mo;k>>=1;x=1ll*x*x%mo;}
	return ans;
}
int inv(int x){return ksm(mod(x),mo-2);}
int read()
{
	char ch=0;int x=0,flag=1;
	while(!isdigit(ch)){ch=getchar();if(ch=='-')flag=-1;}
	while(isdigit(ch)){x=(x<<3)+(x<<1)+ch-'0',ch=getchar();}
	return x*flag;
}
void write(int x)
{
	if(!x)return (void)putchar(48);
	if(x<0)putchar(45),x=-x;
	int len=0,p[20];
	while(x)p[++len]=x%10,x/=10;
	for(int i=len;i>=1;i--)putchar(p[i]+48);
}
const db eps=1e-7,inf=1e9+7,pi=acos(-1);
db Read(){db x;scanf("%lf",&x);return x;}
void Write(db x){printf("%lf",x);}
struct edge{int to,nxt;}e[N*2];
int num,head[N];
inline void add(int x,int y){e[++num]={y,head[x]};head[x]=num;}
stack<int>st;
bool in_stack[N]; 
int times,bel_cnt,dfn[N],low[N],bel[N];
void tarjan(int x)
{
	dfn[x]=low[x]=++times;
	st.push(x);in_stack[x]=true;
	for(int i=head[x];i!=-1;i=e[i].nxt)
	{
		int to=e[i].to;
		if(!dfn[to])tarjan(to),low[x]=min(low[x],low[to]);
		else{if(in_stack[to])low[x]=min(low[x],dfn[to]);}
	}
	if(dfn[x]==low[x])
	{
		int u;
		bel_cnt++;
		do
		{
			u=st.top();st.pop();
			in_stack[u]=false;
			bel[u]=bel_cnt;
		}while(x!=u);
	}
}
int a[M][M];
void work()
{
	int n=read(),m=read(),size=n*m;
	
	for(int i=1;i<=n;i++)for(int j=1;j<=m;j++)a[i][j]=read();
	for(int i=1;i<=n;i++)for(int j=1;j<=m;j++)
	{
		int x=(i-1)*m+j,y;
		if(i-1>=1)
		{
			y=(i-2)*m+j;
			if(a[i][j]==a[i-1][j])add(x,y+size),add(x+size,y);
			if(a[i][j]==a[i-1][j]+1)add(x,y);
			if(a[i][j]==a[i-1][j]-1)add(x+size,y+size);
		}
		if(j-1>=1)
		{
			y=(i-1)*m+j-1;
			if(a[i][j]==a[i][j-1])add(x,y+size),add(x+size,y);
			if(a[i][j]==a[i][j-1]+1)add(x,y);
			if(a[i][j]==a[i][j-1]-1)add(x+size,y+size);
		}
		if(i+1<=n)
		{
			y=i*m+j;
			if(a[i][j]==a[i+1][j])add(x,y+size),add(x+size,y);
			if(a[i][j]==a[i+1][j]+1)add(x,y);
			if(a[i][j]==a[i+1][j]-1)add(x+size,y+size);
		}
		if(j+1<=m)
		{
			y=(i-1)*m+j+1;
			if(a[i][j]==a[i][j+1])add(x,y+size),add(x+size,y);
			if(a[i][j]==a[i][j+1]+1)add(x,y);
			if(a[i][j]==a[i][j+1]-1)add(x+size,y+size);
		}
	}
	
	for(int i=1;i<=2*size;i++)if(!dfn[i])tarjan(i);
	
	for(int i=1;i<=size;i++)
	{
		int x=(i-1)/m+1,y=(i-1)%m+1;
		if(bel[i]>=bel[i+size])a[x][y]++;
		write(a[x][y]);putchar(y==m?'\n':' ');
	}
	
	while(!st.empty())st.pop();
	times=bel_cnt=0;
	for(int i=0;i<=2*size+2;i++)
	{
		head[i]=-1;
		dfn[i]=low[i]=bel[i]=in_stack[i]=false;
	}
	
}
int main()
{
	num=-1;memset(head,-1,sizeof(head));
	int t=read();
	for(int i=1;i<=t;i++)work();
	return 0;
}

