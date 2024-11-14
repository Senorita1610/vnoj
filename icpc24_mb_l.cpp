#include<bits/stdc++.h>
using namespace std;
const int mod = 1e9+7;
int n;
int32_t main(){
	ios::sync_with_stdio(0);
	cin.tie(0); 
	cout.tie(0);
	map<int,int> mp;
	cin >> n;
	long long res = 0;
	for (int i = 0; i < n; i++){
		int a; cin >> a;
		res += mp[a];
		mp[a]++;
	}
	cout << res%mod << "\n";
}

