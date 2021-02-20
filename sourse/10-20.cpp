#include <cstdio>
#define Ha 998244353
int n,m,p,q;
long long jc[210],ny[210],S[110],ans;

struct Matrix{long long v[105][105];} A,B;
Matrix mul(Matrix X,Matrix Y){
	Matrix Z={0};
	for (int i=1; i<=p; i++)
		for (int j=1; j<=p; j++)
			for (int k=1; k<=p; k++)
				Z.v[i][j]=(Z.v[i][j]+X.v[k][j]*Y.v[i][k])%Ha;
	return Z;
}
Matrix Mksm(Matrix X,int y){
	Matrix Z={0};
	for (int i=1; i<=p; i++) Z.v[i][i]=1;
	for (; y; y>>=1,X=mul(X,X)) if (y&1) Z=mul(Z,X);
	return Z; 
}

long long ksm(long long x,int y){
	long long ret=1;
	for (; y; y>>=1,x=x*x%Ha) if (y&1) ret=ret*x%Ha;
	return ret;
}

long long C(int x,int y){
	if (x<y) return 0;
	if (y==0 || x==y) return 1;
	return jc[x]*ny[y]%Ha*ny[x-y]%Ha;
}

void getA(){
	for (int i=1; i<=p; i++)
		for (int j=1; j<=p; j++){
			A.v[i][j]=C(p-j,q-j);
			A.v[i][j]=A.v[i][j]*C(p-q+j,i-q+j)%Ha;
			A.v[i][j]=A.v[i][j]*C(n-1,i-1)%Ha;
			A.v[i][j]=A.v[i][j]*jc[i]%Ha;
		}
}

int main(){
	freopen("1.txt","r",stdin);
	freopen("2.txt","w",stdout);
	scanf("%d%d%d%d",&n,&m,&p,&q);
	jc[0]=1;
	for (int i=1; i<=205; i++) jc[i]=jc[i-1]*i%Ha;
	ny[205]=ksm(jc[205],Ha-2);
	for (int i=204; i>0; i--) ny[i]=ny[i+1]*(i+1)%Ha;
	getA();
	B=Mksm(A,m-1);
	for (int i=1; i<=p; i++) S[i]=C(p,i)*C(n-1,i-1)%Ha*jc[i]%Ha;
	for (int i=1; i<=p; i++)
		for (int k=1; k<=p; k++)
			ans=(ans+S[k]*B.v[i][k]%Ha)%Ha;
	//printf("%lld",ans);
	puts("");
	for (int i=1; i<=p; i++){
		for (int j=1; j<=p; j++) printf("%d\t",A.v[i][j]);
		puts("");
	}
} 
