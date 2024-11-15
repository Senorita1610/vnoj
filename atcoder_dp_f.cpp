#pragma GCC optimize("O3,unroll-loops")
#include<iostream>
#include<iomanip>
#include<cmath>
#include<utility>
#include<cassert>
#include<algorithm>
#include<vector>
#include<array>
#include<cstring>
#include<functional>
#include<numeric>
#include<set>
#include<queue>
#include<map>
#include<chrono>
#include<random>
#define sz(x) ((int)(x.size()))
#define all(x) x.begin(),x.end()
#define pb push_back
#define eb emplace_back
#define kill(x,s) {if(x){cout<<s<<"\n";return;}}
#ifndef LOCAL
#define cerr while(0) cerr
#endif
using ll = long long;
using lb = long double;
const lb eps = 1e-9;
const ll mod = 1e9+7,ll_max=1e18;
const int MX=3366+10,int_max=0x3f3f3f3f;
struct{
	template<class T>
	operator T(){
		T x;
		std::cin>>x;
		return x;
	}
}in;
using namespace std;
int dp[MX][MX];
void solve(){
	string a= (string)in;
	string b= (string)in;
	for(int i=1;i<=sz(a);i++){
		for(int j=1;j<=sz(b);j++){
			dp[i][j]=max({dp[i-1][j],dp[i][j-1],dp[i-1][j-1]+(a[i-1]==b[j-1])});
		}
	}
	int x=sz(a),y=sz(b);
	string ans;
	while(x>0&&y>0){
		if(dp[x-1][y]==dp[x][y]){
			x--;
		}else if(dp[x][y-1]==dp[x][y]){
			y--;
		}else{
			ans.pb(a[x-1]);
			x--,y--;
		}
	}
	reverse(all(ans));
	cout<<ans<<"\n";
}
signed main(){
	cin.tie(0) -> sync_with_stdio(0);
	int T=1;
	for(int i=1;i<=T;i++){
		solve();
	}
	return 0;
}

