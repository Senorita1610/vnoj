#include<iostream>
#include<cstring>
#include<algorithm>
#include<vector>
#include<cmath>
using namespace std;
typedef long long ll;
const int N=3e3+10;
const int INF=1e9;
int n,m;
int a[N];
int f[N][N];
int tmp[N],sz[N];
struct Edge{
	int to,val;
};
vector<vector<Edge>>G(N);
void add(int u,int v,int w){
	G[u].push_back({v,w});
}
void dfs(int u){
	if(G[u].size()==0){
		sz[u]=1;
		f[u][1]=a[u];
		return;
	}
	for(int k=0;k<G[u].size();k++){
		int v=G[u][k].to,w=G[u][k].val;
		dfs(v);
		for(int i=0;i<=sz[u];i++){
			tmp[i]=f[u][i];
		}
		for(int i=sz[u]+1;i<=sz[u]+sz[v];i++) tmp[i]=-INF;
		for(int i=0;i<=sz[u];i++){
			for(int j=0;j<=sz[v];j++){
				tmp[i+j]=max(tmp[i+j],f[u][i]+f[v][j]-w);
			}
		}
		for(int i=0;i<=sz[u]+sz[v];i++) f[u][i]=tmp[i];
		sz[u]+=sz[v];
	}
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int u=1;u<=n-m;u++){
		int k;
		cin>>k;
		while(k--){
			int v,w;
			cin>>v>>w;
			add(u,v,w);
		}
	}
	for(int i=n-m+1;i<=n;i++) cin>>a[i];
	dfs(1);
	for(int i=sz[1];i>=0;i--){
		if(f[1][i]>=0){
			cout<<i<<endl;
			break;
		}
	}
	return 0;
}

