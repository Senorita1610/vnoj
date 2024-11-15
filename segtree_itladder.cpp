#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
#define elif else if 
#define fastIO ios_base::sync_with_stdio(0); cin.tie(0)
const int MAXN = 1e5 + 5;
const int MOD = 1e9 + 7;
int n, q;
int st[4 * MAXN], lazyA[4 * MAXN], lazyB[4 * MAXN];
void fix(int id, int l, int r) {
    if (!lazyA[id] && !lazyB[id])
        return;
    int len = r - l + 1;
    st[id] = (st[id] + lazyA[id] * (len * (len - 1) / 2) % MOD + lazyB[id] * len % MOD) % MOD;
    if (l != r) {
        int mid = (l + r) >> 1;
        lazyA[2*id] = (lazyA[2*id] + lazyA[id]) % MOD;
        lazyB[2*id] = (lazyB[2*id] + lazyB[id]) % MOD;
        lazyA[2*id + 1] = (lazyA[2*id + 1] + lazyA[id]) % MOD;
        lazyB[2*id + 1] = (lazyB[2*id + 1] + lazyB[id] + lazyA[id] * (mid - l + 1) % MOD) % MOD;
    }
    lazyA[id] = 0;
    lazyB[id] = 0;
}

void update(int id, int l, int r, int u, int v, int A, int B) {
    fix(id, l, r);
    if (l > v || r < u)
        return;
    if (l >= u && r <= v) {
        lazyA[id] = (lazyA[id] + A) % MOD;
        lazyB[id] = (lazyB[id] + B + A * (l - u) % MOD) % MOD;
        fix(id, l, r);
        return;
    }
    int mid = (l + r) >> 1;
    update(2*id, l, mid, u, v, A, B);
    update(2*id + 1, mid + 1, r, u, v, A, B);
    st[id] = (st[2*id] + st[2*id + 1]) % MOD;
}
int get(int id, int l, int r, int u, int v) {
    fix(id, l, r);
    if (l > v || r < u)
        return 0;
    if (l >= u && r <= v) 
        return st[id];
    int mid = (l + r) >> 1;
    int x = get(2*id, l, mid, u, v);
    int y = get(2*id + 1, mid + 1, r, u, v);
    return (x + y) % MOD;
}
signed main() {
    fastIO;
    cin >> n >> q;
    int T, L, R, A, B;
    while (q--) {
        cin >> T;
        if (T == 1) {
            cin >> L >> R >> A >> B;
            update(1, 1, n, L, R, A, B);
        }
        else {
            cin >> L >> R;
            cout << get(1, 1, n, L, R) << endl;
        }
    }
    return 0;
}

