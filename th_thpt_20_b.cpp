#include <bits/stdc++.h>  
 
using namespace std;
 
typedef long long ll;
const ll MXN = 2e6 + 5;
const long long INF = 1e15;
const ll MOD = 1e9+7;
const double eps = 1e-12;
#define forn(i,e) for(ll i = 0; i < e; i++)
#define forsn(i,s,e) for(ll i = s; i < e; i++)
#define rforn(i,s) for(ll i = s; i >= 0; i--)
#define rforsn(i,s,e) for(ll i = s; i >= e; i--)
#define ln "\n"
#define dbg(x) cout<<#x<<" = "<<x<<ln
#define mp make_pair
#define pb push_back
#define fi first
#define se second
#define INF 2e18
#define fast_cin() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define all(x) (x).begin(), (x).end()
#define sz(x) ((ll)(x).size())
ll n;
const ll LimN = 1e6+5;
void solve(){
    freopen("CAU2.INP", "r",stdin);
    freopen("CAU2.OUT","w",stdout);
    cin >> n;
    unordered_map<ll,ll> mp;
    ll res = -0x3f;
    for(ll i=1;i<=n;i++){
        ll x; cin >> x;
        mp[x]++;
        res=max(res,mp[x]);
    }
    cout << res;
}
int main()
{
    fast_cin();
    solve();
    return 0;
}

