#include                    <bits/stdc++.h>
using                       namespace std;
#define fi                  first
#define se                  second
#define endl                cout<<'\n';
//Data types macros
#define int                 long long //uncomment if needed
using ll =                  long long;
using ull =                 unsigned long long;
using ldb =                 long double; //or double if TL is tight
using str =                 string; //python type
using ii =                  pair<int, int>;
using mii =                 map<int, int>;
#define mp                  make_pair
#define tcT                 template<class T
#define tcTU                tcT, class U
tcT > using V =             vector<T>;
using vi =                  V<int>;
using vb =                  V<bool>;
using vll =                 V<ll>;
using vull =                V<ull>;
using vldb =                V<ldb>;
using vii =                 V<ii>;
using vstr =                V<str>;
//Vector functions
#define sz(x)               (int)(x.size())
#define bg(x)               x.begin()
#define all(x)              bg(x), x.end
#define rall(x)             x.rbegin(), x.rend()
#define grt                 greater<int>()
#define ft                  front
#define bk                  back
#define pb                  push_back
#define lb(v,x)             lower_bound(all(v),x)
#define ub(v,x)             upper_bound(all(v),x)
#define ld(v,x)             lower_bound(rall(v),x,grt);
#define ud(v,x)             upper_bound(rall(v),x,grt);
//Loops
#define FOR(i,a,b)          for (int i=(a); i<(b); i++)
#define FORD(i,a,b)         for (int i=(a)-1; i>=(b); i--)
#define F0R(i,a)            FOR(i,0,a)
#define F0RD(i,a)           FORD(i,0,a)
#define FORE(i,a)           for (auto i:a)
//File accessing
const string FI =           "sample";
const string IFI =          FI + ".inp";
const string OFI =          FI + ".out";
void opf(bool c){           if (c == 1){
freopen(IFI.c_str(),        "r", stdin);
freopen(OFI.c_str(),        "w", stdout);}}
//Constants
const ldb PI =              3.14159265358979;
const int maxI =            INT_MAX;
const ll maxll =            LLONG_MAX;
const int N =               1e6;
const int mod  =            1e9 + 7;
mt19937 rng((uint32_t)chrono::steady_clock::now().time_since_epoch().count());
//------------------------------------------------------------------------------------
//Code here
vector<int> v(N, 0);
struct FT{
    vector<int> ft;

    int n = 0;
    void init(int _n){
        ft.assign(_n + 9, 0);
        n = _n;
    }
    void update1(int pos, int val){
        while (pos <= n){
            ft[pos] += val;
            pos += pos&(-pos);
        }
    }
    void update2(int pos, int val){
        int tmp = pos;
        while (pos <= n){
            ft[pos] -= v[tmp];
            ft[pos] += val;
            pos += pos&(-pos);
        }
        v[tmp] = val;
    }
    int get(int pos){
        int sum = 0;
        while (pos > 0){
            sum += ft[pos];
            pos -= pos&(-pos);
        }
        return sum;
    }
    int sum(int l, int r){
        return get(r) - get(l - 1);
    }
    void print(){
        for (auto it : ft) cout << it << " ";
    }
};
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    opf(0);
    int n, q;
    cin >> n >> q;
    FT ft;
    ft.init(n);
    for (int i=1; i<=n; i++){
        cin >> v[i];
        ft.update1(i, v[i]);
    }
    while (q--){
        int t, l, r;
        cin >> t >> l >> r;
        if (t == 1){
            ft.update2(l, r);
        }
        else{
            cout << ft.sum(l, r) << "\n";
        }
    }
}

