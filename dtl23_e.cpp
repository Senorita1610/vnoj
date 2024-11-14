#include<bits/stdc++.h>
using namespace std;
const int N=2e5;
int t,n;
vector<vector<int>>adj;
int h[N+5],cnt[N+5];
long long mod=1e9+7,g[N+5];
long long power(long long x,long long y) {
	if (y==1) return x%mod;
	long long ans=power(x,y/2);
	ans=(ans*ans)%mod;
	if (y%2==1) ans=(ans*x)%mod;
	return ans;
}
long long di(long long x,long long y) {
	return (x*power(y,mod-2))%mod;
}
long long C(int k,int n) {
	return di(g[n],(g[k]*g[n-k])%mod);
}
void dfs(int u,int par) {
	cnt[h[u]]++;
	for (auto v:adj[u]) {
		if (v==par) continue;
		h[v]=h[u]+1;
		dfs(v,u);
	}
}
int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);	
    g[0]=1;
    for (int i=1;i<=N;i++) g[i]=(g[i-1]*i)%mod;
	cin>>t;
	while (t--) {
		long long res=0;
		adj.clear();
		cin>>n;
		adj.resize(n+1);
		cnt[n]=0;
		for (int i=1;i<n;i++) {
			cnt[i]=0;
			int u,v;
			cin>>u>>v;
			adj[u].push_back(v);
			adj[v].push_back(u);
		}
		h[1]=1;
		dfs(1,0);
		for (int x=1;x<=n;x++) {
			res+=(((cnt[x]*C(x,n))%mod)*g[n-x])%mod;
			res%=mod;
		}
		cout<<res<<'\n';
	}
}

