#include<bits/stdc++.h>
using namespace std;
double p[6][11],c[11];
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	for (int i=1;i<=5;i++) {
		for (int j=0;j<=10;j++) {
			cin>>p[i][j];
			p[i][j]/=100;
		}
	}
	for (int i=0;i<=10;i++){
		for (int j=0;j<=10;j++) {
			for (int k=0;k<=10;k++) {
				for (int m=0;m<=10;m++) {
					for (int n=0;n<=10;n++) {
						int temp=i+j+k+m+n;
						temp=(temp+4)/5;
						c[temp]+=p[1][i]*p[2][j]*p[3][k]*p[4][m]*p[5][n];
					}
				}
			}
		}
	}
	cout.precision(9);
	for (int i=0;i<=10;i++) cout<<fixed<<c[i]*100<<' ';
}

