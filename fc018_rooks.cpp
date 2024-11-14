#include<bits/stdc++.h>
using namespace std;
const int mod=1e4+3;
int n,m,K;
int dp[55][55][105];
inline void add(int &a,int b){
	a=(a+b>=mod)?a+b-mod:a+b;
}
int main(){
	scanf("%d%d%d",&n,&m,&K);
	if(K>min(n,m)*2){
		printf("0");
		return 0;
	}
	dp[0][0][0]=1;
	for(int i=0;i<n;i++){
		for(int j=0;j<=m;j++){
			for(int k=0;k<=K;k++){
				int c0=m-j-(k-j*2),c1=m-j-c0;
				add(dp[i+1][j][k],dp[i][j][k]);
				add(dp[i+1][j][k+1],dp[i][j][k]*c0%mod);
				add(dp[i+1][j+1][k+1],dp[i][j][k]*c1%mod);
				add(dp[i+1][j][k+2],dp[i][j][k]*c0*(c0-1)/2%mod);
				add(dp[i+1][j+1][k+2],dp[i][j][k]*c0*c1%mod);
				add(dp[i+1][j+2][k+2],dp[i][j][k]*c1*(c1-1)/2%mod);
			}
		}
	}
	int ans=0;
	for(int i=0;i<=m;i++) add(ans,dp[n][i][K]);
	printf("%d",ans);
	return 0;
}

