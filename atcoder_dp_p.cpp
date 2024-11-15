#include<bits/stdc++.h>
#define inf 0x3f3f3f3f
#define INF 0x3f3f3f3f3f3f3f3f
#define i32 INT_MAX
#define i64 LONG_LONG_MAX
#define pii pair<int,int>
#define pll pair<long long,long long>
#define pb push_back
typedef long long ll;
using namespace std;
const int N=1e5+10,mod=1e9+7;
ll read(){
	ll x=0,f=1;
	char c=getchar();
	while(c<'0'||c>'9'){
		if(c=='-') f=-1;c=getchar();
	}
	while(c>='0'&&c<='9'){
		x=(x<<3)+(x<<1)+(c^48);
		c=getchar();
	}
	return x*f;
}
void print(ll x){
	if(x<0) putchar('-'),x=-x;
	if(x>9) print(x/10);putchar(x%10+48);
}
char gc(){
	char c=getchar();
	while(c==' '||c=='\n') c=getchar(); return c;
}
int n,cnte;
int head[N];
ll dp[N][2];
struct edge{
	int v,nxt;
}e[N<<1];
void adde(int u,int v){
	e[++cnte]=(edge){v,head[u]};
	head[u]=cnte;
}
void dfs(int u,int f){
	dp[u][1]=dp[u][0]=1;
	for(int i=head[u];i;i=e[i].nxt){
		int v=e[i].v;
		if(v==f) continue;
		dfs(v,u);
		dp[u][0]*=(dp[v][0]+dp[v][1])%mod;
		dp[u][0]%=mod;
		dp[u][1]*=dp[v][0];
		dp[u][1]%=mod;
	}
}
int main(){
	cin>>n;
	for(int i=1;i<n;i++){
		int u=read(),v=read();
		adde(u,v);
		adde(v,u);
	}
	dfs(1,0);
	cout<<(dp[1][0]+dp[1][1])%mod;
	return 0;
}

