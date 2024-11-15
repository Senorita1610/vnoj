#include<iostream>
#include<cstdio>
#include<cstring>
#include<vector>
#include<algorithm>
using namespace std;
#define ll long long
#define il inline
#define N 100005
il ll read(){
	ll x=0,f=1;char c=getchar();
	while(c<'0'||c>'9'){
		if(c=='-'){
			f=-1;
		}
		c=getchar();
	}
	while(c>='0'&&c<='9'){
		x=(x<<3)+(x<<1)+(c^48);
		c=getchar();
	}
	return x*f;
}
struct Edge{
	int nxt,u,v;
};
Edge edge[N<<1];
int head[N],num_edge;
int n,m,dp[N],ans=-1;
il void add_edge(int u,int v){
	edge[++num_edge].nxt=head[u];
	edge[num_edge].u=u,edge[num_edge].v=v;
	head[u]=num_edge;
}
void dfs(int u){
	if(dp[u]!=-1) return;
	for(int i=head[u];i;i=edge[i].nxt){
		int v=edge[i].v;
		dfs(v);
		dp[u]=max(dp[u],dp[v]+1);
	}
	ans=max(ans,dp[u]);
}
int main(){
	n=read(),m=read();
	for(int i=1;i<=m;i++) add_edge(read(),read());
	memset(dp,-1,sizeof dp);
	for(int i=1;i<=n;i++) dfs(i);
	printf("%d\n",ans+1);
	return 0;
}

