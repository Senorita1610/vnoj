#include <bits/stdc++.h>
using namespace std;
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int m, n;
    cin >> m >> n;
    int p, q;
    cin >> p >> q;
    int ans = 0;
    for (int dx = -1; dx <= 1; dx++) {
        for (int dy = -1; dy <= 1; dy++) {
            int x = p + dx;
            int y = q + dy;
            if (x >= 1 && x <= m && y >= 1 && y <= n) {
                ans++;
            }
        }
    }
    cout << ans - 1 << '\n';
    return 0;
}

