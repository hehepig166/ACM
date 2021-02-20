#include <cstdio>
#include <cstring>
#include <iostream>
#include <string>
#include <algorithm>
#define For(x) for(int h=head[x],vv=v[h]; h; vv=v[h=nxt[h]])
using namespace std;
int n,N,GG=0;
string a[2005],ans[2000];

struct Tu{
	int head[2000],nxt[4000],v[4000],cnt,f[2000],vf[4000],ru[2000],chu[2000];
	string s[4000];
	void Add(int x,int y,string ss){
		cnt++;
		nxt[cnt]=head[x];
		v[cnt]=y;
		s[cnt]=ss;
		head[x]=cnt;
	}
	
	void liantong(int x){
		if (f[x]) return;
		f[x]=1;
		For(x) liantong(vv);
	}
	
	bool check(){
		int S=0,T=0;
		for (int i=0; i<26; i++){
			if (ru[i]==chu[i]) continue;
			if (ru[i]==chu[i]+1){T++; continue;}
			if (chu[i]==ru[i]+1){S++; continue;}
			return 0;
		}
		if (S>1 || T>1) return 0;
		return 1;
	}
	
	void dfs(int x,int dep,int H){
		if (dep==n){
			GG=1;
			ans[dep]=s[H];
			return;
		}
		For(x) if (!vf[h]){
			vf[h]=1;
			dfs(vv,dep+1,h);
			if (GG){
				ans[dep]=s[H];
				return;
			}
			vf[h]=0;
		}
	}
	
}A,B;

int main(){
	cin >>n;
	for (int i=1; i<=n; i++) cin >>a[i];
	sort(a+1,a+n+1);
	for (int i=0; i<26; i++) B.f[i]=1;
	for (int i=n,uuu,vvv; i; i--){
		uuu=a[i][0]-'a';
		vvv=a[i][a[i].length()-1]-'a';
		A.Add(uuu,vvv,a[i]);
		B.Add(uuu,vvv,a[i]);
		B.Add(vvv,uuu,a[i]);
		A.ru[vvv]++;
		A.chu[uuu]++;
		B.f[vvv]=0;
		B.f[uuu]=0;
	}
	
	
	int OK=1;
	B.liantong(a[1][0]-'a');
	for (int i=0; i<26; i++) if (!B.f[i]) OK=0;
	if (!OK || !A.check()){
		printf("***");
		return 0;
	}
	
	
	
	N=0;
	for (int i=0; i<26; i++) if (A.ru[i]+1==A.chu[i]){
		for (int j=1; j<=A.cnt; j++) A.vf[j]=0;
		A.dfs(i,0,0);
		for (int i=1; i<n; i++) cout <<ans[i] <<".";
		cout <<ans[n];
		return 0;
	}
	for (int i=0; i<26; i++) if (A.ru[i]){
		for (int j=1; j<=A.cnt; j++) A.vf[j]=0;
		A.dfs(i,0,0);
		for (int i=1; i<n; i++) cout <<ans[i] <<".";
		cout <<ans[n];
		return 0;
	}
	
}

/*
5
enjyy
yp
pe
ejg
gutio

*/
