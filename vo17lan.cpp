#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

const int N = 50010;

int n, a[N];
vector <int> dvs;
int ans;

void solve() {
    cin >> n; dvs.clear(); ans = 1;
    for (int i = 1; i <= n; ++i) cin >> a[i];
    int x = a[1];
    for (int i = 1; 1LL * i * i <= x; ++i) if (x % i == 0) {
        dvs.push_back(i); if (i != x / i) dvs.push_back(x/i);
    }

    for (int i = 0; i < dvs.size(); ++i) {
        int d = dvs[i];
        if (d <= ans) continue;
        int r1 = 0;
        int r2 = 0;
        for (int j = 1; j <= n; ++j) {
            if (a[j] % d == 0) {
                if (!r1) r1 = a[j]/d; else r1 = __gcd(r1, a[j]/d);
            }
            else {
                if (!r2) r2 = a[j]; else r2 = __gcd(r2, a[j]);
            }
        }
        if (r1 > 1) continue;
        if (r2 == 0) { ans = max(ans, d); continue; }
        ans = max(ans, min(d, r2));
    }

    printf("%d\n", ans);
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int t; cin >> t;
    while(t--) solve();
}

