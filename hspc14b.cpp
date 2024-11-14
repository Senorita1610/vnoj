#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> ii;
typedef pair<long long, int> lli;
typedef long long ll;
typedef unsigned long long ull;

#define For(i,a,b) for(int i=a;i<=b;i++)
#define Rep(i,a,b) for(int i=a;i>=b;i--)
#define FOR(i, f) for(__typeof(f.begin()) i = f.begin(); i != f.end(); i++)
#define fi first
#define se second
#define pb push_back
#define sz(s) int(s.size())
#define reset(f, x) memset(f, x, sizeof(f))
#define all(x) x.begin(), x.end()
#define two(x) (1LL << x)
#define bit(x, i) ((x >> i) & 1LL)
#define onbit(x, i) (x | (1LL << i))
#define N 100010

int n, m, a[N], t[N], b[N], rank[N], sl[N], cnt;
vector<ii> q;
bool was[N];
ll res;

void trau() {
    res = 0;
    For(i, 1, m) For(j, i+1, n) if (a[i] > a[j]) swap(a[i], a[j]), res++;
    cout << res << endl;
}

bool cmp(ii a, ii b) {
    if (a.fi != b.fi) return a.fi < b.fi;
    return a.se < b.se;
}

void init() {
    res = 0;
    reset(t, 0); reset(sl, 0);
    sort(all(q));
    int dem = 0;
    For(i, 0, sz(q)-1) {
    	if (!i || q[i].fi != q[i-1].fi) dem++;
    	if (i < m) cnt = dem;
    	a[q[i].se] = dem; rank[q[i].se] = i+1;
	}
}

void update(int i) {
    for(i; i <= n; i += i & (-i)) t[i]++;
}

int get(int i) {
    int s = 0;
    for(i; i; i -= i & (-i)) s += t[i];
    return s;
}

int main() {
    while (scanf("%d%d", &n, &m) != -1) {
        q.clear();
        For(i, 1, n) {
            int x; scanf("%d", &x);
            q.push_back(ii(x, i));
        }
        cnt = 0;
        init();
        res = 0;
        reset(was, false);
        For(i, 1, n) b[i] = get(a[i]), update(a[i]);
        For(i, 1, n) if (!was[a[i]]) {
            was[a[i]] = true;
            int time = b[i];
            if (time <= m) res += min(m, rank[i]) - time;
        }
        cout << res - cnt << endl;
    }
}

