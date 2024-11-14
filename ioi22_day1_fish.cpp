#include <bits/stdc++.h>
using namespace std;
 
using i32 = int;
using i64 = long long;
template <typename T>
using V = vector<T>;
template <typename T>
using VV = V<V<T>>;
template <typename T>
using VVV = V<V<V<T>>>;
 
template <typename T>
bool chmin(T &x, const T &y) {
    if (x > y) {
        x = y;
        return true;
    }
    return false;
}
template <typename T>
bool chmax(T &x, const T &y) {
    if (x < y) {
        x = y;
        return true;
    }
    return false;
}
 
#define OVERRIDE4(a, b, c, d, ...) d
#define REP2(i, n) for (i32 i = 0; i < (i32)(n); ++i)
#define REP3(i, l, r) for (i32 i = (i32)(l); i < (i32)(r); ++i)
#define REP(...) OVERRIDE4(__VA_ARGS__, REP3, REP2)(__VA_ARGS__)
#define PER2(i, n) for (i32 i = (i32)(n)-1; i >= 0; --i)
#define PER3(i, l, r) for (i32 i = (i32)(r)-1; i >= (i32)(l); --i)
#define PER(...) OVERRIDE4(__VA_ARGS__, PER3, PER2)(__VA_ARGS__)
#define ALL(x) begin(x), end(x)
#define LEN(x) (i32) size(x)
 
void dbg(i32 x) { cerr << x; }
void dbg(i64 x) { cerr << x; }
template <typename T, typename U>
void dbg(pair<T, U> p) {
    cerr << '(' << p.first << ", " << p.second << ')';
}
template <typename T>
void dbg(V<T> arr) {
    cerr << '[';
    REP(i, LEN(arr)) {
        if (i) {
            cerr << ", ";
        }
        dbg(arr[i]);
    }
    cerr << ']';
}
void debug() { cerr << '\n'; }
template <typename Head, typename... Tail>
void debug(Head head, Tail... tail) {
    dbg(head);
    cerr << ", ";
    debug(tail...);
}
#ifdef DEBUGF
#define DBG(...)                       \
    do {                               \
        cerr << #__VA_ARGS__ << " : "; \
        debug(__VA_ARGS__);            \
    } while (false)
#else
#define DBG(...) (void)0
#endif
 
constexpr i64 INF = 3003003003003003003;
 
long long max_weights(i32 n, i32 m, V<i32> x, V<i32> y, V<i32> w) {
    VV<pair<i32, i64>> wts(n);
    REP(i, m) {
        wts[x[i]].emplace_back(y[i], w[i]);
    }
    REP(i, n) {
        sort(ALL(wts[i]));
    }
    V<i64> mxr(n + 1, 0);
    VV<i64> up(n), down(n);
    REP(i, n) {
        up[i].resize(LEN(wts[i]), -INF);
        down[i].resize(LEN(wts[i]), -INF);
    }
    REP(i, LEN(wts[0])) {
        up[0][i] = wts[0][i].second;
    }
    REP(i, n) {
        if (i > 0) {
            REP(j, LEN(wts[i])) {
                chmax(up[i][j], mxr[i - 1] + wts[i][j].second);
                chmax(down[i][j], mxr[i - 1] + wts[i][j].second);
                {
                    auto itr = lower_bound(ALL(wts[i - 1]), pair<i32, i64>(wts[i][j].first, 0LL));
                    if (itr != begin(wts[i - 1])) {
                        i32 idx = itr - begin(wts[i - 1]) - 1;
                        chmax(up[i][j], up[i - 1][idx] + wts[i][j].second);
                    }
                }
                {
                    auto itr = lower_bound(ALL(wts[i - 1]), pair<i32, i64>(wts[i][j].first + 1, 0LL));
                    if (itr != end(wts[i - 1])) {
                        i32 idx = itr - begin(wts[i - 1]);
                        chmax(down[i][j], down[i - 1][idx] + wts[i][j].second);
                    }
                }
            }
            i64 pmax = -INF;
            REP(j, LEN(wts[i - 1])) {
                chmax(pmax, down[i - 1][j]);                
            }
            REP(j, LEN(wts[i])) {
                chmax(up[i][j], pmax + wts[i][j].second);
            }
        }
        PER(j, LEN(wts[i]) - 1) {
            chmax(down[i][j], down[i][j + 1] + wts[i][j].second);
        }
        REP(j, 1, LEN(wts[i])) {
            chmax(up[i][j], up[i][j - 1] + wts[i][j].second);
        }
        chmax(mxr[i + 1], mxr[i]);
        REP(j, LEN(wts[i])) {
            chmax(mxr[i + 1], up[i][j]);
            chmax(mxr[i + 1], down[i][j]);
        }
    }
    i64 ans = mxr[n - 1];
    REP(i, LEN(wts[n - 1])) {
        chmax(ans, down[n - 1][i]);
    }
    return ans;
}

