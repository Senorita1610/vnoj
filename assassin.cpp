#pragma GCC optimize ("O2,unroll-loops,no-stack-protector")
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int>ii;
const int N=1005;
int n,m;
int timer,tplt,zz;
int num[N],low[N],lab[N],vis[N],linked[N];
vector<int>ke[N],G[N];
stack<int>st;
void tarjan(int u){
	num[u]=low[u]=++timer;
	st.push(u);
	for(int v:ke[u]){
		if(num[v]) low[u]=min(low[u],num[v]);
		else{
			tarjan(v);
			low[u]=min(low[u],low[v]);
		}
	}
	if(low[u]==num[u]){
		int v;
		++tplt;
		do{
			v=st.top();
			st.pop();
			lab[v]=tplt;
			low[v]=num[v]=INT_MAX;
		}while(v!=u);;
	}
}
void dfs(int u,int key){
	if(vis[u]==key) return;
	vis[u]=key;
	if(lab[u]!=key) G[key].push_back(lab[u]);
	for(int v:ke[u]){
		dfs(v,key);
	}
}
void Reset(){
	timer=0,tplt=0;
	while(!st.empty()) st.pop();
	for(int i=1;i<=n;i++){
		ke[i].clear();
		G[i].clear();
		num[i]=low[i]=0;
		vis[i]=linked[i]=0;
		lab[i]=0;
	}
}
bool trav(int u,int key){
	for(int v:G[u]){
		if(vis[v]==key) continue;
		if(linked[v]==false){
			linked[v]=u;
			return 1;
		}
	}
	for(int v:G[u]){
		if(vis[v]==key) continue;
		vis[v]=key;
		if(trav(linked[v],key)){
			linked[v]=u;
			return 1;
		}
	}
	return 0;
}
void solve(){
	cin>>n>>m;
	Reset();
	for(int i=1;i<=m;i++){
		int u,v;
		cin>>u>>v;
		ke[u].push_back(v);
	}
	for(int i=1;i<=n;i++) if(!num[i]) tarjan(i);
	for(int i=1;i<=n;i++){
		int u=lab[i];
		if(G[u].empty()==false) continue;
		dfs(i,lab[i]);
	}
	int res=tplt;
	fill(vis+1,vis+1+n,0);
	for(int i=1;i<=tplt;i++){
		if(trav(i,i)) --res;
	}
	cout<<"Case "<<++zz<<": "<<res<<"\n";
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int tc;
	cin>>tc;
	while(tc--){
		solve();
	}
}

