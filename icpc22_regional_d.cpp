#include<algorithm>
#include<iostream>
#include<utility>
#include<cstring>
#include<vector>
#include<queue>
#include<set>
#define int long long
using namespace std;
const int N=5e5+5;
int dp[N][10]={};
vector<int>vec[N];
int v[N];
set<int>st;
int n,m,x,y,z,ans;
void dfs(int now,int index){
	dp[now][index]=1,v[now]=1,st.insert(now);
	for(int i=0;i<vec[now].size();i++) if(!dp[vec[now][i]][index^1]) dfs(vec[now][i],index^1);
}
signed main(){
	ios_base::sync_with_stdio(0);
	cin>>n>>m;
	for(int i=1;i<=m;i++) cin>>x>>y,vec[x].push_back(y),vec[y].push_back(x);
	for(int i=1;i<=n;i++){
		if(!v[i]){
			st.clear(),dfs(i,0),x=y=z=0;
			for(int i:st) x+=dp[i][0],y+=dp[i][1],z+=dp[i][0]*dp[i][1];
			ans+=x*x+y*y-z*z;
		}
	}
	cout<<ans<<endl;
	return 0;
}

