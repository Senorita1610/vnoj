#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> ii;
typedef pair<long long, int> lli;
typedef long long ll;
typedef unsigned long long ull;

#define For(i,a,b) for(int i=a;i<=b;i++)
#define Rep(i,a,b) for(int i=a;i>=b;i--)
#define REP(i, n) for(int i = 0; i < n; i++)
#define FOR(i, f) for(__typeof(f.begin()) i = f.begin(); i != f.end(); i++)
#define fi first
#define se second
#define pb push_back
#define sz(s) int(s.size())
#define reset(f, x) memset(f, x, sizeof(f))
#define all(x) x.begin(), x.end()
#define two(x) (1LL << x)
#define getbit(x, i) ((x >> (i-1)) & 1LL)
#define onbit(x, i) (x | (1LL << (i-1)))
#define offbit(x, i) (x & ~(1 << (i-1)))
#define N 100010

int n, k, a[N], res, d, c, ans;
vector<int> ke[N];
vector<int> st[N];
int cha[N];

int dfs(int u, int x) {
    int sum = a[u];
    st[u].clear();
    FOR(v, ke[u]) if (!cha[*v]) {
        cha[*v] = u;
        int y = dfs(*v, x);
        st[u].pb(y); sum += y;
    }
    sort(all(st[u]));
    int i = sz(st[u]) - 1;
    while (sum > x) {
        sum -= st[u][i];
        i--;
        ans++;
    }
    return sum;
}

bool check(int x) {
    ans = 0;
    reset(cha, 0);
    cha[1] = 1;
    dfs(1, x);
    if (ans <= k) return true;
    return false;
}

int main() {
    scanf("%d%d", &n, &k);
    For(i, 1, n) {
        scanf("%d", a+i);
        d = max(d, a[i]);
        c += a[i];
    }
    For(i, 1, n-1) {
        int u, v;
        scanf("%d%d", &u, &v);
        ke[u].pb(v); ke[v].pb(u);
    }
    while (d <= c) {
        int mid = (d + c) / 2;
        if (check(mid)) {
            res = mid;
            c = mid - 1;
        } else d = mid + 1;
    }
    cout << res;
}

