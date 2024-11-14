#include <bits/stdc++.h>
using namespace std;

#define ll long long
const ll MOD = 1e9 + 7;
const int P = 31;
const int N = 1e4 + 5;
const int INF = 1e9;

int k, n, l[15], f[8195];
ll h[N][2], p[N];
string s;

int GetHash(int i, int j) {
    return (h[j][0] - h[i - 1][0] * p[j - i + 1] + MOD * MOD) % MOD;
}

int GetRevHash(int i, int j) {
    return (h[i][1] - h[j + 1][1] * p[j - i + 1] + MOD * MOD) % MOD;
}

bool IsPalind(int i, int j) {
    return (j <= n && GetHash(i, j) == GetRevHash(i, j));
}

void optimize(int& f, int val) {
    if (~f)
        f = min(f, val);
    else
        f = val;
}

signed main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    cin >> s >> k;
    n = s.size();
    s = " " + s;
    for (int i = 1; i <= n; i++)
        h[i][0] = (h[i - 1][0] * P + (int)s[i]) % MOD;
    for (int i = n; i > 0; i--)
        h[i][1] = (h[i + 1][1] * P + (int)s[i]) % MOD;

    p[0] = 1;
    for (int i = 1; i <= 10000; i++)
        p[i] = p[i - 1] * P % MOD;
    vector <vector <int>> v(n);
    for (int len = 0; len < n; len++)
        for (int i = 1; i <= n - len; i++) 
            if (IsPalind(i, i + len))
                v[len].push_back(i);
    
    while (k--) {
        int m; cin >> m;
        for (int i = 0; i < m; i++) {
            cin >> l[i];
            l[i]--;
        }
        int M = (1 << m);
        fill(f, f + M, INF);
        f[0] = 0;
        for (int mask = 0; mask < M; mask++)
            if (f[mask] <= n) {
                for (int i = 0; i < m; i++)
                    if (!(mask & (1 << i)) && l[i] + f[mask] < n) {
                        auto it = upper_bound(v[l[i]].begin(), v[l[i]].end(), f[mask]);
                        if (it != v[l[i]].end()) 
                            optimize(f[mask | (1 << i)], *it + l[i]);
                    }
            }
        cout << (f[--M] <= n ? "YES\n" : "NO\n");
   }
    return 0;
}

