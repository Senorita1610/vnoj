#include<bits/stdc++.h>
using namespace std;
const int N=1e4;
int n,k,res;
vector<vector<int>>adj(N+5);
int dp[N+5];
void dfs(int u,int par) {
	dp[u]=1;
	for (auto v:adj[u]) {
		if (v==par) continue;
		dfs(v,u);
		dp[u]+=dp[v];
	}
	if (dp[u]>=k) {
		res++;
		dp[u]=0;
	}
}
int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);	
	cin>>k>>n;
	for (int i=2;i<=n;i++) {
		int temp;
		cin>>temp;
		adj[temp].push_back(i);
		adj[i].push_back(temp);
	} 
	dfs(1,0);
	cout<<res;
}

