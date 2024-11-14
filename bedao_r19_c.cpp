#include<bits/stdc++.h>

using namespace std;
const int maxN = 1e6+6;
typedef pair<int,int> ii;
int n, a[maxN], trace[maxN];
ii f[maxN];
void solve(){
	cin >> n;
	ii res = {-1e9,0};
	for (int i = 1; i <= n; i++){
		cin >> a[i];
		f[a[i]] = max(f[a[i]],{f[a[i]+1].first+1,i});
		trace[i] = f[a[i]+1].second;
		res = max(res, f[a[i]]);
	}
	cout << res.first << "\n";
	int pos = res.second;
	vector<int> vec;
	for (int i = 0; i < res.first; i++){
		vec.push_back(pos);
		pos = trace[pos];
	}
	reverse(vec.begin(), vec.end());
	for (int x: vec){
		cout << x << " ";
	}
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	solve();
}

