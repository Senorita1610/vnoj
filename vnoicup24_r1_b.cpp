#include<bits/stdc++.h>

using namespace std;
#define int long long
const int maxN = 2e5+5;
int n, a[maxN], b[maxN];
void solve(){
	cin >> n;
	for (int i = 1; i <= n; i++){
		cin >> a[i];
	}
	for (int i = 1; i <= n; i++){
		cin >> b[i];
	}
	for (int i = 2; i <= n; i++){
		int x = a[i-1]/2;
		a[i-1] %= 2;
		a[i] += x;
	}
	for (int i = n; i > 0; i--){
		if (a[i]<b[i]){
			cout << "NO\n";
			return;
		}
		a[i] -= b[i];
		a[i-1] += a[i]*2;
		a[i-1] = min(a[i-1],(int)1e12);
	}
	cout << "YES\n";
}

main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int t; cin >> t;
	while (t--)
	solve();
}

