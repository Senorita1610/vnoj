#include <bits/stdc++.h>
using namespace std;
const int N = 1e3 + 3;
int n, q;
vector<int> a[N];
map<int, int> mp[N];
signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> q;
    for (int i = 1; i <= n; i++) {
        int m, x;
        cin >> m;
        for (int j = 1; j <= m; j++) {
            cin >> x;
            a[i].push_back(x);
            mp[i][x]++;
        }
    }
    while (q--) {
        int x, maxFre = 0, tmp = 0;
        cin >> x;
        for (int i = 1; i <= n; i++) {
            if (mp[i][x]) tmp++;
            else {
                maxFre = max(maxFre, tmp);
                tmp = 0;
            }
        }
        maxFre = max(maxFre, tmp);
        cout << maxFre << "\n";
    }
}

