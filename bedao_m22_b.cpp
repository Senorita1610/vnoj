#include <bits/stdc++.h>
using namespace std;
#define nothing ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
#define endl "\n"
#define ll long long
const int maxn = 1e6 + 5;
ll n, a[maxn + 2], ans = 0;
map<ll, ll> cnt;
int main() {
    nothing
    cin >> n;
    for (int i = 1; i <= n; ++i) {
    	cin >> a[i];
    	if (i >= 7) cnt[a[i - 6] % 23]++;
    	
    	ans += cnt[a[i] % 23];
    }
    cout << ans << endl;
    return 0;
}

