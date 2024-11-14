#include <bits/stdc++.h>
 
using namespace std;
using ll = long long;
 
//#define int long long
#define FOR(i, a, b) for (int i = (a); i <= (b); i++)
#define FORD(i, a, b) for (int i = (b); i >= (a); i --)
#define REP(i, a) for (int i = 0; i < (a); ++i)
#define REPD(i, a) for (int i = (a) - 1; i >= 0; --i)
 
#define MASK(i) (1LL << (i))
#define BIT(x, i) (((x) >> (i)) & 1)
 
 
constexpr ll LINF = (1ll << 60);
constexpr int INF = (1ll << 30);
constexpr int Mod = 1e9 + 7;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
 
/*
    Phu Trong from Nguyen Tat Thanh High School for gifted student
*/
 
template <class X, class Y>
    bool minimize(X &x, const Y &y){
        X eps = 1e-9;
        if (x > y + eps) {x = y; return 1;}
        return 0;
    }
 
template <class X, class Y>
    bool maximize(X &x, const Y &y){
        X eps = 1e-9;
        if (x + eps < y) {x = y; return 1;}
        return 0;
    }
int nArr, numQuery;
#define MAX             500005
int A[MAX];
struct Queries{
    int l, r, id;
    Queries(){}
    Queries(int _l, int _r, int _id){
        l = _l, r = _r, id = _id;
    }
 
    bool operator < (const Queries& oth) const{
        return r < oth.r;
    }
} Q[MAX];
 
struct custom_hash{
    size_t operator ()(uint64_t x) const{
        static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
        x ^= FIXED_RANDOM;
        return x ^ (x >> 16);
    }
};
unordered_map<int, int, custom_hash> pos;
int pre[MAX];
 
struct FenwickTree{
    vector<int> F;
    int n;
    FenwickTree(int _n = 0){
        this -> n = _n;
        F.resize(n + 5);
    }
    int low_bit(int p){
        return p & (-p);
    }
    void upd(int p, int v){
        for (; p <= n; p += low_bit(p)) F[p] += v;
    }
    int query(int p){
        int res = 0;
        for (; p > 0; p -= low_bit(p)) res += F[p];
        return res;
    }
};
int ans[MAX];
void process(void){
    cin >> nArr >> numQuery;
    for (int i = 1; i <= nArr; ++i) cin >> A[i];
 
    for (int i = 1; i <= numQuery; ++i){
        cin >> Q[i].l >> Q[i].r;
        Q[i].id = i;
    }
    sort(Q + 1, Q + numQuery + 1);
    FenwickTree ft(nArr);
    int j = 1;
    for (int r = 1; r <= nArr; ++r){
        int p = pos[A[r]];
        if(pre[p]){
            ft.upd(pre[p], -1);
            if(pre[pre[p]]) ft.upd(pre[pre[p]], 1);
        }
        pre[r] = pos[A[r]]; pos[A[r]] = r;
        if(pre[r]) ft.upd(pre[r], 1);
        if(pre[pre[r]]) ft.upd(pre[pre[r]], -1);
        while (j <= numQuery && Q[j].r == r){
            ans[Q[j].id] = ft.query(Q[j].r) - ft.query(Q[j].l - 1);
            ++j;
        }
    }
    for (int i = 1; i <= numQuery; ++i){
        cout << ans[i] << '\n';
    }
}
signed main(){
    cin.tie(nullptr) -> sync_with_stdio(false);
    process();
    return (0 ^ 0);
}

