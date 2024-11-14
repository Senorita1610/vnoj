#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fi first
#define se second
#define vi vector<int>
#define vvi vector< vector<int> >
#define endl '\n'

int sqr(int k) {
	return (k * k) % 7;
}
int mod(int k) {
	return (k + 7000000) % 7;
}
int n;
void solve() {
	cin >> n;
	
	int a[n + 5] = {}, 
	    sum[n + 5] = {}, 
	    sqrsum[n + 5] = {};
	cin >> a[1]; 
	a[1] %= 7;
	sum[1] = a[1]; 
	sqrsum[1] = (a[1] * a[1]) % 7;
	for(int i = 2; i <= n; i++) 
	{
		cin >> a[i];
		sum[i] = (sum[i - 1] + a[i]) % 7;
		sqrsum[i] = (sqrsum[i - 1] + a[i] * a[i]) % 7;
	}
	int dp[7][7] = {}, ans = 0;
	for(int i = 0; i <= n; i++)
	{
		for(int sumj = 0; sumj < 7; sumj++) 
		{
			int sqrProd = sqr(sumj - sum[i]);
			ans += dp[sumj][mod(sqrsum[i] - sqrProd)];

		}
		dp[sum[i]][sqrsum[i]]++;
	}
	cout << ans;
}
signed main() {
	ios_base:: sync_with_stdio(0);
	cin.tie(NULL); cout.tie(NULL);
	solve();
}

