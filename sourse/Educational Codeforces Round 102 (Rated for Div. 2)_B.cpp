#include <cstdio>
#include <string>
#include <iostream>
using namespace std;

int check(const string &x, const string &y) {	// y/x ?
	int n=x.length(),m=y.length();
	int i,j;
	int ret=0;
	for (i=-1; i<m-1; ret++) {
		for (j=0; j<n; j++) {
			i++;
			if (i>=m || x[j]!=y[i]) {
				return 0;
			}
		}
	}
	return ret;
}

int gcd(int x, int y) {return y ? gcd(y,x%y) : x;}

int main()
{
	int T;
	cin >>T;
	string A,B,tmp;
	int l;
	while (T--) {
		cin >>A >>B;
		if (A.length()<B.length()) {
			swap(A,B);
		}
		
		if (A.length()==B.length()) {
			if (A==B) {
				cout <<A <<endl;
			}
			else {
				cout <<-1 <<endl;
			}
		}
		else {
			tmp="";
			int l=B.length(),i,n1,n2,nn;
			for (i=0; i<l; i++) {
				tmp+=B[i];
				n1=check(tmp,A);
				n2=check(tmp,B);
				if (n1 && n2) {
					break;
				}
			}
			if (i==l) {
				cout <<-1 <<endl;
			}
			else {
				nn=gcd(n1,n2);
				nn=n1*n2/nn;
				for (int k=1; k<=nn; k++) {
					cout <<tmp;
				}
				cout <<endl;
			}
			
		}
		
	}
	return 0;
}
