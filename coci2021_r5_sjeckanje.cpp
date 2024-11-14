#include<bits/stdc++.h>
using namespace std;
#define FOR(i, a, b)  for(int i = (a), _b = (b); i <= _b; ++i)
#define FORD(i, b, a) for(int i = (b), _a = (a); i >= _a; --i)
#define REP(i, a, b)  for(int i = (a), _b = (b); i < _b;  ++i)
#define REPD(i, b, a) for(int i = (b), _a = (a); i > _a;  --i)
#define MASK(i) (1LL << (i))
#define BIT(mask, i) (((mask) >> (i)) & 1)
#define __builtin_popcount __builtin_popcountll
#define all(val) val.begin(), val.end()
#define ll long long
#define ull unsigned long long
#define pii pair<int, int>
#define pll pair<ll, ll>
#define sz(v) (int)v.size()
#define fi first
#define se second
 
mt19937_64 rng(chrono::high_resolution_clock::now().time_since_epoch().count());
ll Rand(ll l, ll r) {return l + rng() % (r - l + 1);}
 
template<class X, class Y>
    bool minimize(X &x, const Y &y) {
        if (x > y) {
            x = y;
            return true;
        } else return false;
    }
template<class X, class Y>
    bool maximize(X &x, const Y &y) {
        if (x < y) {
            x = y;
            return true;
        } else return false;
    }
template<class T>
    T Abs(const T &x) {
        return (x < 0 ? -x : x);    
    }
 
const int mod = 1e9 + 7;
const int inf = 1e9;
const int N = 2e5 + 5;
 
struct node {
    ll a[2][2];
    node() { memset(a, 0, sizeof(a)); }
};
 
int n, q;
int a[N], d[N];
node st[N << 2];
 
node combine(node &l, node &r, int &pos) {
    node res;
    if(1ll * d[pos] * d[pos + 1] < 0) {
        REP(i, 0, 2) REP(j, 0, 2)
            res.a[i][j] = max(l.a[i][0] + r.a[1][j], l.a[i][1] + r.a[0][j]);
    } else {
        REP(i, 0, 2) REP(j, 0, 2) 
            res.a[i][j] = l.a[i][1] + r.a[1][j];
    }
    return res;
}
 
void update(int pos, int id = 1, int l = 1, int r = n) {
    if(l == r) {
        st[id].a[1][1] = abs(d[l]);
        return;
    }
    int m = l + r >> 1;
    if(pos <= m) update(pos, id << 1, l, m);
    else update(pos, id << 1 | 1, m + 1, r);
    st[id] = combine(st[id << 1], st[id << 1 | 1], m);
}
 
void process() {
    cin >> n >> q;
    FOR(i, 1, n) {
        cin >> a[i];
        if(i > 1) {
            d[i] = a[i] - a[i - 1];
            update(i);
        }
    }
    while(q--) {
        int l, r, x; cin >> l >> r >> x;
        if(l > 1) {
            d[l] += x;
            update(l);
        }
        if(r < n) {
            d[r + 1] -= x;
            update(r + 1);
        }
        cout << st[1].a[1][1] << '\n';
    }
}
 
signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    process();
    return 0;
}

