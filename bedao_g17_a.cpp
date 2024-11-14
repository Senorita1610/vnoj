#include<bits/stdc++.h>

using namespace std;
#define ld long double
int n, q;
void solve(){
	cin >> n >> q;
	vector<pair<long long,long long>> vec;
	vec.push_back({0,0});
	for (int i = 1; i <= n; i++){
		long long x, y, w; cin >> x >> y >> w;
		vec.push_back({x*x+y*y,w});
	}
	sort(vec.begin(),vec.end());
	for (int i = 1; i < vec.size(); i++) vec[i].second += vec[i-1].second;
	while (q--){
		long long r; cin >> r;
		long long pos = (*(--upper_bound(vec.begin(),vec.end(),pair<long long,long long>{r*r,(long long)1e18}))).second;
		cout << pos << "\n";
	}
}

int32_t main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	solve();
}

