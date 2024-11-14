#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
int n,q,cnt=0,up[N][18],Log[N];
int in[N],out[N],depth[N];
long long bit[N];
vector<pair<int,int>>adj[N];
vector<tuple<int,int,int>>edges;
void update(int x,int val){
	for(;x<=n;x+=(x&-x)){
		bit[x]+=val;
	}
}
long long get(int x){
	long long ans=0;
	for(;x>0;x-=(x&-x)){
		ans+=bit[x];
	}
	return ans;
}
void dfs(int u,int p){
	in[u]=++cnt;
	for(auto [v,w]:adj[u]){
		if(v==p) continue;
		depth[v]=depth[u]+1;
		up[v][0]=u;
		for(int i=1;i<18;i++){
			up[v][i]=up[up[v][i-1]][i-1];
		}
		dfs(v,u);
	}
	out[u]=cnt;
}
int lca(int u,int v){
	if(depth[u]<depth[v]) swap(u,v);
	int k=depth[u]-depth[v];
	for(int i=0;(1<<i)<=k;i++){
		if(k>>i&1) u=up[u][i];
	}
	if(u==v) return u;
	k=Log[depth[u]];
	for(int i=k;i>=0;i--){
		if(up[u][i]!=up[v][i]){
			u=up[u][i];
			v=up[v][i];
		}
	}
	return up[u][0];
}
void solve(){
	cin>>n;
	for(int i=1;i<n;i++){
		int u,v,w;
		cin>>u>>v>>w;
		adj[u].push_back({v,w});
		adj[v].push_back({u,w});
		edges.push_back({u,v,w});
	}
	for(int i=2;i<=n;i++) Log[i]=Log[i/2]+1;
	cin>>q;
	dfs(1,0);
	for(auto [u,v,w]:edges){
		if(depth[u]<depth[v]) swap(u,v);
		update(in[u],w);
		update(out[u]+1,-w);
	}
	while(q--){
		int type,u,v,i,w,ww;
		cin>>type;
		if(type==1){
			cin>>i>>w;
			u=get<0>(edges[i-1]),v=get<1>(edges[i-1]),ww=get<2>(edges[i-1]);
			if(depth[u]<depth[v]) swap(u,v);
			update(in[u],w-ww);
			update(out[u]+1,-(w-ww));
			edges[i-1]={u,v,w};
		}
		else{
			cin>>u>>v;
			int t=lca(u,v);
			cout<<get(in[v])+get(in[u])-2*get(in[t])<<endl;
		}
	}
}
int32_t main(){
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	solve();
}

