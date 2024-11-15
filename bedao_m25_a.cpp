#include<bits/stdc++.h>

using namespace std;
#define int long long
const int mod = 1e9+7;
int n, a;
void solve(){
	cin >> n;
	int sum1 = 0, sum2 = 0, sqr1 = 0, sqr2 = 0, c1 = 0, c2 = 0;
	for (int i = 1; i <= n; i++){
		cin >> a;
		if (a%2) sum1 += a, sqr1 += a*a, c1++;
		else sum2 += a, sqr2 += a*a, c2++; 
	}
	int res = 0;
	res += sum2%mod*c1 + sum1%mod*c2;
	cout << res%mod << "\n";
}

int32_t main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	solve();
}

