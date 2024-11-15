#pragma GCC optimize("Ofast")
#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const int MOD = 1000000007;
#define sz(x) (ll)(x).size()
#define rd ({ll x; cin>>x; x;})
#define dbg(x) cerr<<"[" #x "] "<<(x)<<"\n\n"
#define xx first
#define yy second
void Solve(){
	ll n,w;
	cin>>n>>w;
	vector<pair<ll,ll>>arr(n);
	for(int i=0;i<n;i++){
		cin>>arr[i].xx>>arr[i].yy;	
	}
	vector<ll>dp(w+1,0);
	for(auto& it : arr){
		for(int i=w;i>=it.xx;i--){
			dp[i]=max(dp[i],dp[i-it.xx]+it.yy);
		}
	}
	cout<<*max_element(dp.begin(),dp.end())<<endl;
}
int main(){
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	Solve();
}

