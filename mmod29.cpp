#include<bits/stdc++.h>
using namespace std;
const int MOD=29;
long long POW(int a,int b){
	long long x=1,y=a;
	while(b>0){
		if(b&1) x=(x*y)%MOD;
		y=(y*y)%MOD;
		b>>=1;
	}
	return x;
}
long long invPow(int n){
	return POW(n,MOD-2);
}
int main(){
	int n;
	while(cin>>n){
		if(n==0) break;
		long long ans=1;
		ans=POW(2,n*2+1)-1;
		ans=ans*(POW(3,n+1)-1)*invPow(2);
		ans=ans*(POW(167,n+1)-1)*invPow(166);
		cout<<ans%MOD<<endl;
	}
}

