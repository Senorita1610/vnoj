#include<bits/stdc++.h>
using namespace std;
#define mx 30004
#define MOD
#define pii pair<int,int>
#define fs first
#define sc second
#define mkp make_pair
#define ll long long
int id[mx];
int sal[mx],h[mx];
vector<int>edge[mx];
int vis[mx];
int sz[mx];
int rid[10000051];
int par[mx];
void dfs(int u){
	vis[u]=1;
	sz[u]=1;
	for(int v:edge[u]){
		par[v]=u;
		dfs(v);
		sz[u]+=sz[v];
	}
}
int main(){
	int t;
	scanf("%d",&t);
	while(t--){
		int n,q;
		scanf("%d%d",&n,&q);
		vector<pair<pii,int>>ara(n);
		for(int i=0;i<n;i++) edge[i].clear();
		for(int i=0;i<n;i++){
			int s,hi;
			scanf("%d%d%d",&id[i],&s,&hi);
			rid[id[i]]=i;
			ara[i]={{hi,s},i};
		}
		sort(ara.rbegin(),ara.rend());
		set<pii>st;
		int cnt[n];
		memset(cnt,0,sizeof cnt);
		int x=0;
		for(int i=0;i<n;i++){
			while(x<n&&ara[x].fs.fs>=ara[i].fs.fs){
				st.insert({ara[x].fs.sc,ara[x].sc});
				x++;
			}
			auto it=st.upper_bound({ara[i].fs.sc+1,-1});
			int maxi=0;
			if(it!=st.end()){
				int j=it->sc;
				edge[j].push_back(ara[i].sc);
				cnt[ara[i].sc]++;
			}
			st.insert({ara[i].fs.sc,ara[i].sc});
		}
		memset(vis,0,sizeof vis);
		memset(par,-1,sizeof par);
		for(int i=0;i<n;i++){
			if(!cnt[i]) dfs(i);
		}
		while(q--){
			int x;
			scanf("%d",&x);
			int idx=rid[x];
			if(par[idx]==-1) printf("0 ");
			else printf("%d ",id[par[idx]]);
			printf("%d\n",sz[idx]-1);
		}
	}
}

