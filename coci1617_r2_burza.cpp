#include<bits/stdc++.h>
using namespace std;
const int maxn=405,sq=20;
int n,k;
vector<int>adj[maxn],dp[maxn];
int cnt[(1<<sq)],nag[maxn],high[maxn],sz,par[maxn];
vector<pair<int,int>>updy[maxn],unnow;
pair<int,int>stf[maxn];
set<pair<int,int>>st;
 
void vorod(){
	cin>>n>>k;
	for(int i=0;i<n-1;i++){
		int u,v;
		cin>>u>>v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	if(k>=20){
		cout<<"DA\n";
		exit(0);
	}
}
 
void del(int u,int x,int len){
	if(u==0||x==0){
		return ;
	}
	sort(adj[u].begin(),adj[u].end());
	adj[u].erase(lower_bound(adj[u].begin(),adj[u].end(),x));
	if((int)adj[u].size()==0){
		st.insert(make_pair(len,u));
	}
}
 
void dfs(int u,int len=0,int para=0){
	del(u,para,len);
	if(len==k){
		adj[u].clear();
	}
	for(auto x:adj[u]){
		par[x]=u;
		dfs(x,len+1,u);
	}
	if((int)adj[u].size()==0){
		st.insert(make_pair(len,u));
	}
}
 
void dfs2(int u=1,int len=0){
	if(adj[u].size()==0){
		sz++;
		nag[sz]=u;
		stf[u].first=stf[u].second=sz;
		return ;
	}
	stf[u].first=sz+1;
	for(auto x:adj[u]){
		dfs2(x,len+1);
	}
	stf[u].second=sz;
}
 
void pre(){
	dfs(1);
	while((int)st.size()>0&&((*st.begin()).first<k)){
		int u=(*st.begin()).second,v=(*st.begin()).first;
		st.erase(*st.begin());
		del(par[u],u,v-1);
	}
	if((int)st.size()==0){
		cout<<"DA\n";
		exit(0);
	}
	dfs2();
}
 
void add(int i,int val){
	if(val>=(1<<sq)){
		exit(0);
	}
	if(cnt[val]==0){
		cnt[val]++;
		dp[i].push_back(val);
	}
}
 
void cl(int i){
	for(auto x:dp[i]){
		cnt[x]=0;
	}
}
 
void solve(){
	for(int i=1;i<=sz;i++){
		int u=nag[i];
		for(int j=k;j>=1;j--){
			if(stf[u].second==i){
				updy[i].push_back(make_pair(stf[u].first-1,j));
			}
			u=par[u];
		}
		for(auto x:updy[i]){
			if(x.first==0){
				add(i,(1<<x.second));
				continue;
			}
			int ind=x.first,z=x.second;
			for(auto y:dp[ind]){
				if(((y>>z)&1)==0){
					add(i,(1<<z)^y);
				}
			}
		}
		cl(i);
	}	
}
 
void khor(){
	if((int)dp[sz].size()==0){
		cout<<"NE\n";
	}else{
		cout<<"DA\n";
	}
}
 
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	vorod();
	pre();
	solve();
	khor();
}

