#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const int maxN=1e2+1;
const int MOD=1e9+7;
map<vector<int>,int>f[maxN];
int mark[8];
int n,k;
void ReadInput(){
	cin>>n>>k;
	for(int i=1;i<=k;i++){
		int x;
		cin>>x;
		mark[x-1]=1;
	}
}
int dp(int i,vector<int>d){
	if(i==n) return 1;
	if(f[i].count(d)) return f[i][d];
	int res=0;
	for(int u=0;u<8;u++){
		if(mark[u]&&d[u]==u){
			vector<int>newd(8);
			for(int v=0;v<8;v++) newd[v]=min(d[v]+1,v);
			newd[u]=0;
			res+=dp(i+1,newd);
			if(res>=MOD) res-=MOD;
		}
	}
	return f[i][d]=res;
}
void Solve(){
	vector<int>d(8);
	iota(d.begin(),d.end(),0);
	cout<<dp(0,d);
}
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	ReadInput();
	Solve();
	return 0;
}

