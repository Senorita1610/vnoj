#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define endl '\n'
#define mp make_pair
#define loop(i, k, n) for(int i = k ; i < n ; i ++)
#define rloop(i, k, n) for(int i = k ; i > n ; i--)
#define ll long long int
#define FIO ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
typedef pair<int, int> PII;

ll x, y;

ll fastPower(ll x, ll n, ll mod){
    ll ans = 1;
    while(n != 0){
        if(n%2 == 1){
            ans *= x;
            ans %= mod;
        }
        x *= x;
        x %= mod;
        n /= 2;
    }
    return ans;
}

ll moduloInverse(ll n, ll mod){
    ll res = fastPower(n, mod-2, mod);
    return res;
    if(mod == 0){
        x = 1;
        y = 0;
        return x;
    }
    ll temp = moduloInverse(mod, n%mod);
    x = y;
    y = temp - (n/mod) * y;
    return x;
}

int main(){
    FIO
    int t;
    cin >> t;
    ll mod = 1e9 + 7;
    while(t--){
        ll n, k, m;
        cin >> n >> k >> m;
        if(m%2 == 1){
            ll temp = ( (n-1) * moduloInverse(n, mod) ) % mod;
            temp = (temp + mod) % mod;
            temp = fastPower(temp, (m+1)/2, mod);
            temp = (temp + mod) % mod;
            ll ans = ( 1 - temp ) % mod;
            ans += mod;
            ans %= mod;
            cout << ans << endl;
        }else{
            ll temp = ( (n-1) * moduloInverse(n, mod) ) % mod;
            temp = (temp + mod) % mod;
            temp = fastPower(temp, m/2, mod);
            temp = (temp + mod) % mod;
            ll temp1 = ( moduloInverse(n+k, mod) * (n+k-1) ) % mod;
            ll ans = (temp * temp1) % mod;
            ans += mod;
            ans %=  mod;
            ans = 1 - ans;
            ans += mod;
            ans %=  mod;
            cout << ans << endl;
        }
    }
    return 0;
}

