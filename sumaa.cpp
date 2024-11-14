#include <bits/stdc++.h>
using namespace std;

const int N = 500000;

int n, h[N], v[N];

struct Node {
    int a, b;
    Node(int a = 0, int b = 0): a(a), b(b) {}
    bool operator < (const Node &rhs) const {
        return 1ll * a * rhs.b < 1ll * rhs.a * b;
    }
};

int cnt;
pair<Node, pair<int, int>> cross[N << 1];

int pa[N], sz[N];

int findset(int x) {
    return pa[x] == x ? x : findset(pa[x]);
}

int ans = 1, tot, mem_x[N], mem_y[N];

void merge(int x, int y) {
    x = findset(x), y = findset(y);

    if (x == y)
        return;

    if (sz[x] < sz[y])
        swap(x, y);

    mem_x[++tot] = x, mem_y[tot] = y;
    pa[y] = x;
    sz[x] += sz[y];
    ans = max(ans, sz[x]);
}

void solve(int x, int y) {
    if (v[x] == v[y]) {
        if (h[x] == h[y])
            merge(x, y);

        return;
    }

    if (v[x] < v[y])
        swap(x, y);

    if (h[x] > h[y])
        return;

    cross[++cnt] = make_pair(Node(h[y] - h[x], v[x] - v[y]), make_pair(x, y));
}

int id(int x, int y) {
    return (x - 1) * n + y;
}

int main() {
    cin >> n;

    for (int i = 1; i <= n * n; ++i)
        cin >> h[i];

    for (int i = 1; i <= n * n; ++i)
        cin >> v[i];

    for (int i = 1; i <= n * n; ++i)
        pa[i] = i, sz[i] = 1;

    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= n; ++j) {
            if (i > 1)
                solve(id(i, j), id(i - 1, j));

            if (j > 1)
                solve(id(i, j), id(i, j - 1));
        }

    sort(cross + 1, cross + cnt + 1);
    tot = 0;

    for (int i = 1; i <= cnt; ++i) {
        if (cross[i - 1].first < cross[i].first) {
            while (tot) {
                pa[mem_y[tot]] = mem_y[tot], sz[mem_x[tot]] -= sz[mem_y[tot]];
                --tot;
            }
        }

        merge(cross[i].second.first, cross[i].second.second);
    }

    cout << ans << "\n";
    return 0;
}

