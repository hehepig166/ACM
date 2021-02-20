#include <cstdio>
char S[200005],T[200005];

struct segment_tree {
	#define LX (X<<1)
	#define RX ((X<<1)|1)
	#define M ((L+R)>>1)
	static const int N=200005;
	int tag[N<<2],cnt[N<<2],len[N<<2];
	
	void push_dn(int X) {
		if (tag[X]>=0) {
			
			tag[LX]=tag[X];
			cnt[LX]=tag[X] ? len[LX] : 0;
			
			tag[RX]=tag[X];
			cnt[RX]=tag[X] ? len[RX] : 0;
			
			tag[X]=-1;
		}
	}
	
	void push_up(int X) {
		cnt[X]=cnt[LX]+cnt[RX];
	}
	
	void build(int X, int L, int R) {
		tag[X]=-1;
		len[X]=R-L+1;
		if (L==R) {
			cnt[X]=T[L]=='1';
			return;
		}
		build(LX,L,M);
		build(RX,M+1,R);
		push_up(X);
	}
	
	void modify(int X, int L, int R, const int &l, const int &r, const int &t) {	//[l,r] -> t
		if (r<L || R<l)
			return;
		
		if (l<=L && R<=r) {
			tag[X]=t;
			cnt[X]=t ? len[X] : 0;
			return;
		}
		else {
			push_dn(X);
			modify(LX,L,M,l,r,t);
			modify(RX,M+1,R,l,r,t);
			push_up(X);
		}
	}
	
	int query(int X, int L, int R, const int &l, const int &r) {
		if (r<L || R<l)
			return 0;
		if (l<=L && R<=r)
			return cnt[X];
		push_dn(X);
		return query(LX,L,M,l,r)+query(RX,M+1,R,l,r);
	}
	
	bool check(int X, int L, int R) {
		bool ret;
		if (L==R) {
			return cnt[X]==(S[L]=='1');
		}
		push_dn(X);
		ret= check(LX,L,M) && check(RX,M+1,R);
		push_up(X) ;
		return ret;
	}
	
} st;

void solve()
{
	static int l[200005],r[200005];
	static int n,q,c1,c0,fail;
	scanf("%d%d",&n,&q);
	scanf("%s%s",S+1,T+1);
	for (int i=1; i<=q; i++) {
		scanf("%d%d",&l[i],&r[i]);
	}
	st.build(1,1,n);
	fail=0;
	for (int i=q; i; i--) {
		c1=st.query(1,1,n,l[i],r[i]);
		c0=r[i]-l[i]+1-c1;
		if (c1==c0) {
			fail=1;
			break;
		}
		if (c1>c0)
			st.modify(1,1,n,l[i],r[i],1);
		else
			st.modify(1,1,n,l[i],r[i],0);
	}
	fail|= !st.check(1,1,n);
	puts(fail ? "NO" : "YES");
}

int main()
{
	int o;
	scanf("%d",&o);
	while (o--) {
		solve();
	}
	return 0;
}
