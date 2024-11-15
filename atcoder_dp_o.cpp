#include<bits/stdc++.h>
using namespace std;
const int N=25,mod=1e9+7;
int n,a[N][N],m,dp[(1<<22)+1];
int main(){
	cin>>n;
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			cin>>a[i][j];
		}
	}
	dp[0]=1;
	for(int s=0,i;s<(1<<n);s++){
		i=__builtin_popcount(s);
		i--;
		m=s;
		for(int j;m;m-=(m&-m)){
			j=__builtin_ctz(m);
			dp[s]=(dp[s]+a[i][j]*dp[s-(1<<j)])%mod;
		}
	}
	cout<<dp[(1<<n)-1];
	return 0;
}

