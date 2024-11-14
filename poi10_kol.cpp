#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e5 + 10;
int n, a[MAXN], ra[MAXN], b[MAXN], c[MAXN], mx[MAXN * 4], mn[MAXN * 4];
int col[MAXN];
inline int ls(int p) { return p << 1; }
inline int rs(int p) { return p << 1 | 1; }
int merge_mx(int x, int y) {
    if (!x || !y) return x | y;
    return a[x] > a[y] ? x : y;
}
int merge_mn(int x, int y) {
    if (!x || !y) return x | y;
    return min(x, y);
}
void build(int p, int l, int r) {
    if (l == r) {
        mx[p] = l, mn[p] = ra[l];
        return;
    }
    int mid = (l + r) >> 1;
    build(ls(p), l, mid);
    build(rs(p), mid + 1, r);
    mx[p] = merge_mx(mx[ls(p)], mx[rs(p)]);
    mn[p] = merge_mn(mn[ls(p)], mn[rs(p)]);
}
void erase_mx(int p, int l, int r, int x) {
    if (l == r) {
        mx[p] = 0;
        return;
    }
    int mid = (l + r) >> 1;
    if (x <= mid) {
        erase_mx(ls(p), l, mid, x);
    } else {
        erase_mx(rs(p), mid + 1, r, x);
    }
    mx[p] = merge_mx(mx[ls(p)], mx[rs(p)]);
}
void erase_mn(int p, int l, int r, int x) {
    if (l == r) {
        mn[p] = 0;
        return;
    }
    int mid = (l + r) >> 1;
    if (x <= mid) {
        erase_mn(ls(p), l, mid, x);
    } else {
        erase_mn(rs(p), mid + 1, r, x);
    }
    mn[p] = merge_mn(mn[ls(p)], mn[rs(p)]);
}
int query_mx(int p, int l, int r, int ql, int qr) {
    if (ql <= l && r <= qr) return mx[p];
    int mid = (l + r) >> 1;
    if (qr <= mid) {
        return query_mx(ls(p), l, mid, ql, qr);
    } else if (ql > mid) {
        return query_mx(rs(p), mid + 1, r, ql, qr);
    } else {
        return merge_mx(query_mx(ls(p), l, mid, ql, qr),
                        query_mx(rs(p), mid + 1, r, ql, qr));
    }
}
int query_mn(int p, int l, int r, int ql, int qr) {
    if (ql <= l && r <= qr) return mn[p];
    int mid = (l + r) >> 1;
    if (qr <= mid) {
        return query_mn(ls(p), l, mid, ql, qr);
    } else if (ql > mid) {
        return query_mn(rs(p), mid + 1, r, ql, qr);
    } else {
        return merge_mn(query_mn(ls(p), l, mid, ql, qr),
                        query_mn(rs(p), mid + 1, r, ql, qr));
    }
}
void dfs(int u) {
    erase_mx(1, 1, n, u);
    erase_mn(1, 1, n, a[u]);
    while (true) {
        int v = query_mn(1, 1, n, b[u], a[u]);
        if (!v || v >= u) break;
        col[v] = col[u] ^ 1, dfs(v);
    }
    while (true) {
        int v = (u < c[a[u]] ? query_mx(1, 1, n, u + 1, c[a[u]]) : 0);
        if (!v || a[v] <= a[u]) break;
        col[v] = col[u] ^ 1, dfs(v);
    }
}
struct fenwick_tree {
    int d[MAXN];
    void update(int p, int x) {
        for (; p <= n; p += p & -p) d[p] += x;
    }
    int query(int p) {
        int ret = 0;
        for (; p >= 1; p -= p & -p) ret += d[p];
        return ret;
    }
} tr[2];
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n;
    for (int i = 1; i <= n; ++i) cin >> a[i], ra[a[i]] = i;
    b[n] = a[n];
    for (int i = n - 1; i >= 1; --i) b[i] = min(b[i + 1], a[i]);
    for (int i = 1, j = 0; i <= n; ++i) {
        while (j < n && b[j + 1] < i) ++j;
        c[i] = j;
    }
    build(1, 1, n);
    fill(col + 1, col + n + 1, -1);
    for (int i = 1; i <= n; ++i)
        if (col[i] == -1) col[i] = 0, dfs(i);
    for (int i = 1; i <= n; ++i) {
        if (tr[col[i]].query(a[i]) != tr[col[i]].query(b[i])) {
            cout << "NIE\n";
            return 0;
        }
        tr[col[i]].update(a[i], 1);
    }
    cout << "TAK\n";
    for (int i = 1; i <= n; ++i) cout << col[i] + 1 << " \n"[i == n];
    return 0;
}

