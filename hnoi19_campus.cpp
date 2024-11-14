#include<bits/stdc++.h>
#define ll long long
#define ull unsigned ll
#define pi pair<int,int>
#define ld long double
#define vi vector<int>
#define all(x) begin(x),end(x)
using namespace std;
inline ll read(){
	ll x=0,f=1;
	char c=getchar();
	for(;!isdigit(c);c=getchar()) if(c=='-') f=-1;
	for(;isdigit(c);c=getchar()) x=(x<<3)+(x<<1)+(c^48);
	return x*f;
}
inline void out(ll x){
	if(x>9) out(x/10);
	putchar(x%10^48);
}
inline void print(ll x,char c='\n'){
	if(x<0) putchar('-'), x=-x;out(x),putchar(c);
}
const int N=5005;
int f;
char c[N],col[N];
bitset<N>dp[N];
vector<int>v[N],g[N];
void dfs1(int x){
	for(int y:v[x]){
		if(c[y]==c[x]){
			if(col[y]==-1) g[x].push_back(y),g[y].push_back(x),col[y]=col[x]^1,dfs1(y);
			else if(col[x]==col[y]&&!f) f=1,g[x].push_back(x);
		}
	}
}
void dfs2(int x){
	for(int y:v[x]) if(c[y]!=c[x]&&col[y]==-1)
		g[x].push_back(y),g[y].push_back(x),col[y]=col[x]^1,dfs2(y); 
}
int main(){
	int n=read(),m=read(),Q=read();
	scanf("%s",c+1);
	for(int i=1;i<=n;i++) c[i]-='0';
	for(int i=1;i<=m;i++){
		int x=read(),y=read();
		v[x].push_back(y),v[y].push_back(x);
	}
	memset(col,-1,sizeof col);
	for(int i=1;i<=n;i++) if(col[i]==-1) col[i]=f=0,dfs1(i);
	memset(col,-1,sizeof col);
	for(int i=1;i<=n;i++) if(col[i]==-1) col[i]=0,dfs2(i);
	queue<pi>q;
	for(int x=1;x<=n;x++){
		dp[x][x]=1,q.push({x,x});
		for(int y:g[x]) if(c[x]==c[y]) dp[x][y]=dp[y][x]=1,q.push({x,y});
	}
	while(q.size()){
		auto[x,y]=q.front();q.pop();
		for(int u:g[x]) for(int v:g[y])
			if(c[u]==c[v]&&!dp[u][v])
				dp[u][v]=dp[v][u]=1,q.push({u,v});
	}
	while(Q--){
		int x=read(),y=read();
		puts(dp[x][y]?"YES":"NO");
	}
}

