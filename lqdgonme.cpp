#include<bits/stdc++.h>
using namespace std;
const int N=1000,M=10;
int n,m;
int dp[N+5];
int a[M+5][N+5],pos[M+5][N+5],res;
bool check(int x,int y) {
	for (int i=1;i<=m;i++) {
		if (pos[i][x]<=pos[i][y]) return false;
	}
	return true;
}
int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);	
	cin>>n>>m;
	for (int i=1;i<=m;i++) {
		for (int j=1;j<=n;j++) {
			cin>>a[i][j];
			pos[i][a[i][j]]=j;
		}
	}
	for (int i=1;i<=n;i++) {
		dp[i]=1;
		for (int j=1;j<=n;j++) {
			if (check(a[1][i],a[1][j])) dp[i]=max(dp[i],dp[j]+1);
		}
		res=max(res,dp[i]);
	} 
	cout<<res;
}

