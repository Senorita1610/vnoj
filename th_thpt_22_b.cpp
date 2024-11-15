#include <bits/stdc++.h>
using namespace std;
#define nothing ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define endl "\n"
#define ll long long
const int maxn = 1e6 + 5;
ll n, a[maxn + 2];
ll candies = 0, cnt = 0;
int main() {
    nothing
    if (fopen("CANDIES.inp", "r")) {
        freopen("CANDIES.inp", "r", stdin);
        freopen("CANDIES.out", "w", stdout);
    }
    cin >> n;
    for (int i = 1; i <= n; ++i) {
    	cin >> a[i];
    	if (a[i] % 3 == 0 && a[i] != 0) 
    		candies += a[i], cnt++;
    }
    cout << cnt << endl << candies / 3 - cnt << endl;
    return 0;
}

