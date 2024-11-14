#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define int ll
#define rep(i,a,b) for(int i=a;i<b;i++)
#define all(x) begin(x),end(x)
#define sz(x) (int)(x).size()
#define PB push_back
#define FS first
#define SD second
#define ary(k) array<int,k>
template<class A,class B> void cmx(A& x,B y){
	x=max(x,y);
}
template<class A,class B> void cmn(A& x,B y){
	x=min(x,y);
}
typedef pair<int,int>pii;
typedef vector<int>vi;
vector<int>v[2505];
int s[2505],p[2505],sz[2505],n,k;
int a[2505];
int dp[2505][2505],nxt[2505];
void dfs(int x){
	sz[x]=1;
	for(auto t:v[x]) dfs(t),sz[x]+=sz[t];
	for(int i=1;i<=min(sz[x],k);i++) dp[x][i]=-1e18;
	int now=1;
	dp[x][now]=a[x];
	for(auto t:v[x]){
		for(int i=1;i<=min(sz[t]+now,k);i++) nxt[i]=-1e18;
		for(int i=1;i<=min(now,k);i++){
			for(int j=0;j<=min(sz[t],k-i);j++){
				nxt[i+j]=max(nxt[i+j],dp[x][i]+dp[t][j]);
			}
		}
		for(int i=1;i<=min(sz[t]+now,k);i++) dp[x][i]=nxt[i];
		now+=sz[t];
	}
}
signed main(){
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);
	cin>>k>>n;
	k++;
	for(int i=1,x;i<=n;i++){
		cin>>s[i]>>p[i]>>x;
		p[i]*=10000;
		v[x].push_back(i);
	}
	int l=0,r=100000000;
	while(l!=r){
		int mid=(l+r+1)/2;
		for(int i=1;i<=n;i++) a[i]=p[i]-s[i]*mid;
		dfs(0);
		if(dp[0][k]>=0) l=mid;
		else r=mid-1;
	}
	l+=5;
	cout<<l/10000<<".";
	int md=l%10000/10;
	if(md<100) cout<<'0';
	if(md<10) cout<<'0';
	cout<<md<<endl;
}

