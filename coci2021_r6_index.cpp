#include <bits/stdc++.h>
using namespace std;
#define fastIO ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define el cout << '\n'
#define debug(x) cout << #x << " = " << x << '\n'
#define execute cerr << "Time elapsed: " << (1.0 * clock() / CLOCKS_PER_SEC) << "s"
#define ll long long
#define ull unsigned long long
#define pii pair<int, int>
#define pll pair<ll, ll>
#define piv pair<int, vector<int>>
#define vi vector<int>
#define vl vector<ll>
#define vc vector<char>
template<typename T> bool maximize(T &res, const T &val) { if (res < val){ res = val; return 1; }; return 0; }
template<typename T> bool minimize(T &res, const T &val) { if (res > val){ res = val; return 1; }; return 0; }
//STL
#define sz(x) (int)(x).size()
#define FOR(i,l,r) for(auto i = l; i <= r; i++)
#define FORD(i,r,l) for(auto i = r; i >= l; i--)
#define forin(i,a) for(auto i : a)
#define pb push_back
#define eb emplace_back
#define pf push_front
#define all(x) (x).begin(), (x).end()
#define fi first
#define se second
//bitmask
#define bitcnt(n) __builtin_popcount(n)
#define mask(i) (1 << (i))
#define bit(n, i) (((n) >> (i)) & 1)
#define set_on(n, i) ((n) | mask(i))
#define set_off(n, i) ((n) & ~mask(i))
//constant
#define N 200005
#define MOD 1000230007
#define INF 0x3f3f3f3f
#define LINF 0x3f3f3f3f3f3f3f3f
#define base 31
#define Kadoc 0
 
int n, q, M;
int a[N];
int ans[N];
vector<int> pos[N];
int t[N];
 
void upd(int x, int v){
    for(;x<=n; x+=x&-x) t[x] += v;
}
 
int get(int x){
    int Ans = 0;
    for(;x; x-=x&-x) Ans += t[x];
    return Ans;
}
 
struct Node{
    int l, r;
} qr[N];
 
void calc(int t, int l, int r, vector<int> &cand){
    if(l > r || !sz(cand)) return;
 
    int m = (l+r)>>1;
    vector<int> candL, candR;
 
    if(t) FOR(x, m, r) for(int i:pos[x]) upd(i, 1);
    else FOR(x, l-1, m-1) for(int i:pos[x]) upd(i, -1);
 
    for(int id:cand){
        if(get(qr[id].r) - get(qr[id].l - 1) >= m) candR.pb(id), ans[id] = m;
        else candL.pb(id);
    }
 
    calc(1, l, m-1, candL);
    calc(0, m+1, r, candR);
 
    if(t) FOR(x, m, r) for(int i:pos[x]) upd(i, -1);
    else FOR(x, l-1, m-1) for(int i:pos[x]) upd(i, +1);
 
    while(candL.size()) candL.pop_back();
    while(candR.size()) candR.pop_back();
}
 
void solve(){
    cin >> n >> q;
    M = 0;
    FOR(i, 1, n){
        cin >> a[i];
        M = max(M, a[i]);
        pos[a[i]].pb(i);
    }
 
    vector<int> v;
    FOR(i, 1, q){
        int l, r; cin >> l >> r;
        qr[i] = {l, r};
        v.pb(i);
    }
 
    calc(1, 1, M, v);
 
    FOR(i, 1, q) cout << ans[i], el;
}
 
int main(){
    fastIO;
    
    if(Kadoc){
        int tc; cin >> tc;
        while(tc--){
            solve();
        }
    } else solve();
}

