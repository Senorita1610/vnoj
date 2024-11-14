#include <iostream>
#include <vector>
 
using namespace std;
 
#define PB push_back
typedef long long ll;
 
const ll maxn = 1e7 + 5;
 
bool prime[maxn];
vector<ll> primes;
 
inline ll szfact (ll a, ll p){
    ll ret = 0;
    for(ll i=p; i<=a; i*=p) {
        ret += a/i;
    }
    return ret;
}
 
inline void solve() {
    ll a,b,c,d;
    cin >> a >> b >> c >> d;
    for(auto p:primes) {
        if(szfact(b,p)-szfact(a-1,p)>szfact(d,p)-szfact(c-1,p)) {
            cout << "NE\n";
            return;
        }
    }
    cout << "DA\n";
}
 
int main() {
    cin.tie(NULL)->sync_with_stdio(false);
    ll t;
    cin >> t;
    for(ll i=2; i<maxn; i++) {
        if(prime[i]) continue;
        for(ll j=i*i; j<maxn; j+=i) prime[j] = true;
        primes.PB(i);
    }
    while(t--) solve();
}

