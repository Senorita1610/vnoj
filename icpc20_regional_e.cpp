#include<bits/stdc++.h>
using namespace std;
#define int long long
#define pb push_back
#define pii pair<int,int>
#define endl '\n'
const int N=3e5+5;
int parent[N],sz[N],e[N][2];
void make_set(int n){
	for(int i=0;i<=n;i++){
		parent[i]=i;
		sz[i]=1;
	}
}
int find_set(int v){
	if(v==parent[v]) return v;
	else return parent[v]=find_set(parent[v]);
}
void union_sets(int a,int b){
	a=find_set(a);
	b=find_set(b);
	if(a!=b){
		if(sz[a]<sz[b]) swap(a,b);
		parent[b]=a;
		sz[a]+=sz[b];
	}
}
int32_t main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t;
	cin>>t;
	while(t--){
		int n,m;
		cin>>n>>m;;
		vector<pii>edges;
		for(int i=0;i<m;i++){
			int u,v,w;
			cin>>u>>v>>w;
			edges.pb({w,i});
			e[i][0]=u;
			e[i][1]=v;
		}
		sort(edges.begin(),edges.end());
		make_set(n);
		vector<int>ans;
		int idx=0;
		while(idx<m){
			int nxt=m;
			vector<int>tmp;
			for(int i=idx;i<m;i++){
				if(edges[i].first!=edges[idx].first){
					nxt=i;
					break;
				}
				if(find_set(e[edges[i].second][0])!=find_set(e[edges[i].second][1]))
					tmp.pb(edges[i].second);
			}
			for(auto i:tmp){
				if(find_set(e[i][0])==find_set(e[i][1])) ans.pb(i+1);
				else union_sets(e[i][0],e[i][1]);
			}
			idx=nxt;
		}
		if(sz[find_set(1)]!=n) cout<<-1<<endl;
		else{
			cout<<ans.size();
			for(auto i:ans) cout<<" "<<i;
			cout<<endl;
		}
	}
}

