#include<bits/stdc++.h>

using namespace std;
const int maxN = 1e6+6;
int n, a[maxN], cnt[30];
void solve(){
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> a[i];
	for (int j = 0; j < 30; j++) cnt[j] = 0;
	for (int i = 1; i <= n; i++){
		for (int j = 0; j < 30; j++) cnt[j] += a[i]>>j&1;
	}
	int res = 0;
	for (int bit = 0; bit < 30; bit++){
		res = max(res, cnt[bit]);
	}
	cout << res << "\n";
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	solve();
}

