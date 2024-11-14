#include<bits/stdc++.h>
#define fi first
#define se second
#define ll long long
#define FOR(i,a,b) for(int i=a,_b=b;i<=_b;i++)
#define FOD(i,b,a) for(int i=b,_=a;i>=_a;i--)
#define NAME "input"
#define vii pair<int,int>
#define Getbit(mask,i) ((mask>>i)&1)
#define MASK(k) (1<<k)
#define ALL(x) x.begin(),x.end()
#define endl '\n'
using namespace std;
int dx[]={-1,0,1,0};
int dy[]={0,1,0,-1};
const int N=2e5+5;
const ll mod=998244353;
const ll INF=1e9+7;
int n,q,sz[N],head[N],tin[N],cnt=0,par[N],pos[N];
vector<int>dsk[N];
struct segg{
	int tree[4*N];
	void build(int id,int l,int r){
		if(l==r){
			tree[id]=INF;
			return;
		}
		int mid=(l+r)>>1;
		build(id*2,l,mid);
		build(id*2+1,mid+1,r);
		tree[id]=min(tree[id*2],tree[id*2+1]);
	}
	void update(int id,int l,int r,int u){
		if(l==r){
			if(tree[id]==INF) tree[id]=l;
			else tree[id]=INF;
			return;
		}
		int mid=(l+r)>>1;
		if(u<=mid) update(id*2,l,mid,u);
		else update(id*2+1,mid+1,r,u);
		tree[id]=min(tree[id*2],tree[id*2+1]);
	}
	int Get(int id,int l,int r,int u,int v){
		if(l>v||r<u) return INF;
		if(u<=l&&r<=v) return tree[id];
		int mid=(l+r)>>1;
		return min(Get(id*2,l,mid,u,v),Get(id*2+1,mid+1,r,u,v));
	}
}it;
void dfs(int u,int p){
	sz[u]=1;
	for(int v:dsk[u]){
		if(v!=p){
			par[v]=u;
			dfs(v,u);
			sz[u]+=sz[v];
		}
	}
}
void hld(int u,int top,int p){
	tin[u]=++cnt;
	pos[cnt]=u;
	head[u]=top;
	int Big=-1;
	for(int v:dsk[u])
	if(v!=p&&(Big==-1||sz[Big]<sz[v])) Big=v;
	if(Big==-1) return;
	hld(Big,top,u);
	for(int v:dsk[u])
	if(v!=p&&v!=Big) hld(v,v,u);
}
int Gett(int v){
	int ans=INF;
	while(head[v]!=1){
		ans=min(ans,it.Get(1,1,n,tin[head[v]],tin[v]));
		v=par[head[v]];
	}
	ans=min(ans,it.Get(1,1,n,tin[1],tin[v]));
	if(ans==INF) return -1;
	else return pos[ans];
}
void giai(){
	cin>>n>>q;
	FOR(i,1,n-1){
		int u,v;
		cin>>u>>v;
		dsk[u].push_back(v);
		dsk[v].push_back(u);
	}
	dfs(1,1);
	hld(1,1,1);
	it.build(1,1,n);
	FOR(i,1,q){
		int t,v;
		cin>>t>>v;
		if(t==0) it.update(1,1,n,tin[v]);
		else cout<<Gett(v)<<endl;
	}
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	giai();
}

