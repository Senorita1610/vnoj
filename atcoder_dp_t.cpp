#include<bits/stdc++.h>
#define _for(i,a,b) for(int i=a;i<=n;i++)
using namespace std;
using LL=long long;
const int N=3e3+5;
const LL mod=1e9+7;
LL D[2][N],S[N][N];
int main(){
	ios::sync_with_stdio(false),cin.tie(0);
	int n;
	string s;
	cin>>n>>s;
	D[1][1]=1,S[1][1]=1;
	_for(i,2,n){
		int x=i%2,y=x^1;
		_for(j,1,i){
			LL &d=D[x][j];
			if(s[i-2]=='>') d=(S[y][i-1]-S[y][j-1]+mod)%mod;
			else d=S[y][j-1];
			S[x][j]=(S[x][j-1]+d)%mod;
		}
	}
	printf("%lld",S[n%2][n]);
	return 0;
}

