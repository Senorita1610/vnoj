#include <bits/stdc++.h>
 
using namespace std;
using ll = long long;
using ld = long double;
using T = tuple<ll, ll, ll>;
 
#define int long long
#define Base 41
#define sz(a) (int)a.size()
#define FOR(i, a, b) for ( int i = a ; i <= b ; i++ )
#define FORD(i, a, b) for (int i = b; i >= a; i --)
#define REP(i, n) for (int i = 0; i < n; ++i)
#define REPD(i, n) for (int i = n - 1; i >= 0; --i)
#define all(x) x.begin() , x.end()
#define pii pair<int , int>
#define fi first
#define se second
#define Lg(x) 31 - __builtin_clz(x)
 
#define MASK(i) (1LL << (i))
#define BIT(x, i) (((x) >> (i)) & 1)
 
constexpr ll LINF = (1ll << 60);
constexpr int INF = (1ll << 30);
constexpr int MAX = 1e5 + 5;
constexpr int Mod = 1e9 + 7;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
 
void setupIO(){
    #define name "Whisper"
    //Phu Trong from Nguyen Tat Thanh High School for gifted student
    srand(time(NULL));
    cin.tie(nullptr)->sync_with_stdio(false); cout.tie(nullptr);
    //freopen(name".inp", "r", stdin);
    //freopen(name".out", "w", stdout);
    cout << fixed << setprecision(10);
}
 
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
 
char a[11][MAX];
int N;
vector<int> ans;
bool dfs(int x, int y){
    if (a[x][y] == 'X') return 0;
    if (y == N - 1) return 1;
    a[x][y] = 'X';
    if (dfs(min(9ll, x + 1), y + 1)){
        return 1;
    }
    if (dfs(max(0ll, x - 1), y + 1)){
        ans.push_back(y);
        return 1;
    }
    return 0;
}
void Whisper(){
    cin >> N;
    FOR(i, 0, 9) cin >> a[i];
    dfs(9, 0);
    reverse(all(ans));
    cout << sz(ans) << '\n';
    for (auto&x : ans) cout << x << " " << 1 << '\n';
}
 
 
signed main(){
    setupIO();
    int Test = 1;
//    cin >> Test;
    for ( int i = 1 ; i <= Test ; i++ ){
        Whisper();
        if (i < Test) cout << '\n';
    }
}

