#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
vector<int> p, q, r;
bool solve(int n, int a, int b, int c) {
    if (b + c > a + n || 1ll * a * b * c < n)
        return 0;

    if (!n)
        return 1;

    if (solve(n - 1, a - 1, b - 1, c - 1)) {
        p.push_back(n);
        q.push_back(n);
        r.push_back(n);
        return 1;
    }

    if (a + b + c - 2 > n) {
        for (int i = 1; i <= n; i++)
            p.push_back(i);

        for (int i = 1; i <= n - 3; i++)
            q.push_back(n - i + 1), r.push_back(n - i + 1);

        q.insert(q.end(), {3, 1, 2});
        r.insert(r.end(), {1, 3, 2});
        return 1;
    }

    set<ll> sp;
    auto posq = [&](ll x) {
        return make_pair(-(x - 1) / a, x);
    };
    auto cmpq = [&](ll x, ll y) {
        return posq(x) < posq(y);
    };
    set<ll, decltype(cmpq)> sq(cmpq);
    auto posr = [&](ll x) {
        return make_pair((x - 1) / a / c, -x);
    };
    auto cmpr = [&](ll x, ll y) {
        return posr(x) < posr(y);
    };
    set<ll, decltype(cmpr)> sr(cmpr);
    auto add = [&](ll x) {
        sp.insert(x);
        sq.insert(x);
        sr.insert(x);
    };

    for (int i = 1; i <= a; i++)
        add(i);

    for (int i = 1; i < b; i++)
        add(1ll * i * a * c + 1);

    for (int i = 1; i < c; i++)
        add(1ll * i * a + 1);

    for (int i = 2, s = a + b + c - 2; s < n; i++)
        if (!sp.count(i))
            add(i), s++;

    map<ll, int> id;
    int t = 0;

    for (ll x : sp)
        p.push_back(id[x] = ++t);

    for (ll x : sq)
        q.push_back(id[x]);

    for (ll x : sr)
        r.push_back(id[x]);

    return 1;
}
int main() {
    int tot;
    scanf("%d", &tot);

    for (int n, a, b, c, op; tot--;) {
        p.clear();
        q.clear();
        r.clear();
        scanf("%d%d%d%d%d", &n, &a, &b, &c, &op);

        if (solve(n, a, b, c)) {
            puts("YES");

            if (!op)
                continue;

            for (int x : p)
                printf("%d ", x);

            puts("");

            for (int x : q)
                printf("%d ", x);

            puts("");

            for (int x : r)
                printf("%d ", x);

            puts("");
        } else
            puts("NO");
    }

    return 0;
}

