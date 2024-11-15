#pragma GCC optimize("Ofast,unroll-loops")
#pragma GCC target("avx2")
#include<bits/stdc++.h>
using namespace std;
using ll = long long;
ll dp[100005];
void solve(int t){
	int n,w;
	cin>>n>>w;
	for(int i=1;i<100005;i++) dp[i]=2e9;
	int tv=0;
	for(int i=0;i<n;i++){
		int wi,vi;
		cin>>wi>>vi;
		tv+=vi;
		for(int j=tv;j-vi>=0;j--){
			dp[j]=min(dp[j],dp[j-vi]+wi);
		}
	}
	for(int i=tv;i>=0;i--){
		if(dp[i]<=w){
			cout<<i;
			break;
		}
	}
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t=1;
	for(int i=1;i<=t;i++) solve(i);
	return 0;
}

