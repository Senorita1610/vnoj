#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> ii;
typedef pair<long long, int> lli;
typedef long long ll;
typedef unsigned long long ull;

#define For(i,a,b) for(int i=a;i<=b;i++)
#define Rep(i,a,b) for(int i=a;i>=b;i--)
#define fi first
#define se second
#define pb push_back
#define sz(s) int(s.size())
#define reset(f, x) memset(f, x, sizeof(f))
#define all(x) x.begin(), x.end()
#define two(x) (1 << x)
#define bit(x, i) ((x >> i) & 1)
#define onbit(x, i) (x | (1 << i))
#define N 100010

struct node {
    int time, game;
    node(int a, int b) {
        time = a; game = b;
    }
};

int n, m, q, x[N], y[N], lef[N], righ[N], res[N], root[N], f[N], a[N];
vector<int> human[N];
vector<node> Q;

bool cmp(node a, node b) {
    return a.time < b.time;
}

int getroot(int u) {
    if (root[u] != u) root[u] = getroot(root[u]);
    return root[u];
}

void Union(int r1, int r2) {
    if (f[r1] < f[r2]) {
        root[r1] = r2;
        f[r2] += f[r1];
    } else {
        root[r2] = r1;
        f[r1] += f[r2];
    }
}

int main() {
    scanf("%d%d%d", &n, &m, &q);
    For(i, 1, n) {
        scanf("%d", &a[i]);
        human[a[i]].pb(i);
    }
    For(i, 1, q) scanf("%d%d", &x[i], &y[i]);
    x[0] = 1; y[0] = 1;
    For(i, 1, n) {
        lef[i] = 0; righ[i] = q; res[i] = -1;
    }
    while (1) {
        Q.clear();
        For(i, 1, m) if (lef[i] <= righ[i]) Q.pb(node((lef[i] + righ[i]) / 2, i));
        if (sz(Q) == 0) break;
        sort(all(Q), cmp);
        For(i, 1, n) {
            root[i] = i; f[i] = 1;
        }
        int j = 0;
        For(i, 0, q) {
            int r1 = getroot(x[i]), r2 = getroot(y[i]);
            if (r1 != r2) Union(r1, r2);
            while (j < sz(Q) && Q[j].time == i) {
                int x = Q[j].game; j++;
                int goc = getroot(human[x][0]);
                bool ok = true;
                For(jj, 1, sz(human[x])-1) {
                    int rr = getroot(human[x][jj]);
                    if (rr != goc) {
                        ok = false;
                        break;
                    }
                }
                if (ok) {
                    res[x] = i; righ[x] = i-1;
                } else lef[x] = i+1;
            }
        }
    }
    For(i, 1, m) printf("%d\n", res[i]);
}

