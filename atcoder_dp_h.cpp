#include<bits/stdc++.h>
using namespace std;
const int mod=1000000007;
int n,m,dp[1003][1003],ans;
string s[1003];
int main(){
	ios::sync_with_stdio(0);
	cin.tie(NULL);
	cout.tie(NULL);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>s[i];
		s[i]=' '+s[i];
	}
	dp[0][1]=1;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			dp[i][j]=(dp[i-1][j]+dp[i][j-1])%mod;
			if(s[i][j]=='#') dp[i][j]=0;
		}
	}
	cout<<dp[n][m];
}

