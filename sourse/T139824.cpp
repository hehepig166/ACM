#include<bits/stdc++.h>
using namespace std;
const int MAXN=1<<22,P=998244353,G=3,Gi=332748118;
typedef unsigned long long ull;
typedef long long ll;
int n,m,s,S,j;
void clr(int*f,int n)
{
  memset(f,0,n<<2);
}
void cpy(int*f,int*g,int n)
{
  memcpy(f,g,n<<2);
}
int fastpow(int a,int k=P-2)
{
  int base=1;
  for(; k; a=(1ll*a*a)%P,k>>=1)
    if(k&1)
      base=(1ll*base*a)%P;
  return base%P;
}
string str1,str2;
int RRRRRRR[MAXN];
void ntt(int*a,int limit,int type)
{
  static ull A[MAXN<<1],w[MAXN<<1];
  w[0]=1;
  for(int i=0,p=limit>>1; i<limit; i++)RRRRRRR[i]=(RRRRRRR[i>>1]>>1)|((i&1)?p:0);
  for(int i=0; i<limit; i++)A[i]=a[RRRRRRR[i]];
  for(int mid=1,l=2,L=1; l<=limit; mid=l,l<<=1,++L)
  {
    ull wn=fastpow(type,P>>L);
    for(int i=1; i<mid; i++)w[i]=w[i-1]*wn%P;
    for(int j=0; j<limit; j+=l)
    {
      for(int k=0; k<mid; ++k)
      {
        int u=j|k,v=u|mid,x=(w[k]*A[v]%P);
        ull y=A[u];
        A[v]=y+P-x;
        A[u]=x+y;
      }
    }
    if(L==17)
      for(int i=0; i<limit; ++i)A[i]%=P;
  }
  if(type==Gi)
  {
    ull inv=fastpow(limit,P-2);
    for(int i=0; i<limit; i++)
      a[i]=A[i]*inv%P;
  }
  else
    for(int i=0; i<limit; i++)
      a[i]=A[i]%P;
}
void NTT(int*f,bool op,int limit)
{
  return ntt(f,limit,op?G:Gi);
}
void px(int*f,int*g,int n)
{
  for(int i=0; i<n; ++i)f[i]=1ll*f[i]*g[i]%P;
}
string bigmul(string str1,string str2)
{
  string c="";
  static int a[MAXN],b[MAXN];
  int N=str1.length(),M=str2.length();
  int n=1,p=N+M-2;
  for(; n<=p; n<<=1);
  clr(a,n<<1),clr(b,n<<1);
  for(int i=0,p=N-1; i!=N; ++i)
    a[i]=str1[p-i]&15;
  for(int i=0,p=M-1; i!=M; ++i)
    b[i]=str2[p-i]&15;
  NTT(a,1,n),NTT(b,1,n),px(a,b,n),NTT(a,0,n);
  for(int i=0; i<=p; ++i)a[i+1]+=a[i]/10,a[i]%=10;
  if(a[p+1]>0)++p;
  for(int i=p; i>=0; --i)
    c+=char(a[i]|48);
  return c;
}



int main()
{
	string hehe,SS,SSS;
	scanf("%d%d%d",&n,&m,&s);
	for (int i=1,tmp; i<=m; i++) scanf("%d",&tmp),S+=tmp;
	stringstream ss;
	ss<<S;
	SS=ss.str();
	SSS=SS;
	for (int i=1; i<n; i++) SS=bigmul(SS,SSS);
	cout <<SS << "\n";
	while (s--){
		cin>>hehe;
		if (hehe=="DH"){
			for (j=1; j<=n; j<<=1);
			j>>=1;
			n-=j;
			SS=SSS;
			for (int i=1; i<n; i++) SS=bigmul(SS,SSS);
			cout <<SS << "\n";
		} 
		if (hehe=="CS"){
			for (j=1; j<=n; j<<=1);
			n+=j;
			SS=SSS;
			for (int i=1; i<n; i++) SS=bigmul(SS,SSS);
			cout <<SS << "\n";
		} 
	}
	/*
	string a,b;
	cin>>a>>b;
	cout<<bigmul(a,b);
	*/
}
