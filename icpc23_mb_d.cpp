#include<bits/stdc++.h>
using namespace std;
const int N=30,P=(1<<16)+1,mod=123456789;
int dp[2][P][257];
vector<int>q;
vector<int>vv[P];
int cnt[P];
int n,m,nd;
bool check(int x,int i){
	if((x>>i)&1) return true;
	return false;
}
void solve(){
	cin>>n>>m>>nd;
	if(n>m) swap(n,m);
	for(int i=0;i<(1<<n);i++){
		int state=i;
		int f=1;
		for(int j=0;j<n-1;j++){
			if(((i>>j)&1)&&((i>>(j+1))&1)){
				f=0;
				break;
			}
		}
		if(f){
			q.push_back(i);
			int res=0;
			for(int j=0;j<n;j++){
				if((i>>j)&1) res++;
			}
			cnt[i]=res;
		}
	}
	for(auto u:q){
		for(auto v:q){
			int f=1;
			for(int i=0;i<n;i++){
				if((u>>i)&1){
					if(!i){
						if(check(v,i)||check(v,i+1)){
							f=0;
							break;
						}
					}
					else if(i==n-1){
						if(check(v,i)||check(v,i-1)){
							f=0;
							break;
						}
					}else{
						if(check(v,i)||check(v,i-1)||check(v,i+1)){
							f=0;
							break;
						}
					}
				}
			}
			if(f) vv[u].push_back(v);
		}
	}
	dp[0][0][0]=1;
	int t=0;
	for(int i=1;i<=m+1;i++){
		for(auto u:q){
			for(auto v:vv[u]){
				for(int k=cnt[u]+cnt[v];k<=nd;k++){
					dp[t^1][u][k]=((long long)dp[t^1][u][k]+dp[t][v][k-cnt[u]])%mod;
				}
			}
		}
		for(auto u:q){
			for(int k=0;k<=256;k++){
				dp[t][u][k]=0;
			}
		}
		t^=1;
	}
	cout<<dp[t][0][nd]<<endl;
}
int main(){
	solve();
	return 0;
}

