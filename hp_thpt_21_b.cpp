#include <bits/stdc++.h>
#define ll long long
using namespace std;

bool nt(int n)
{
    if (n == 2 || n == 3)
        return true;
    if (n < 3 || n % 2 == 0 || n % 3 == 0)
        return false;
    for (int i = 5; i * i <= n; i += 6)
        if (n % i == 0 || n % (i + 2) == 0)
            return false;
    return true;
}

bool check (ll n) {
    if (!nt(n)) return false;
    bool f = false;
    for (ll i = 0; i <= 9; i++) {
        ll temp = n * 10 + i;
        if (nt(temp)) {f = true; break;}
    }
    if (!f) return false;
    if (n >= 10) while (n / 10 != 0) {
        n /= 10;
        if (!nt(n)) return false;
    }
    return true;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll n;
    cin >> n; ll a[n]; for (ll i = 0; i < n; i++) cin >> a[i];
    ll t; cin >> t;
    vector <pair<ll, ll>> p; 
    for (ll i = 0; i < t; i++) {
        ll x, y; cin >> x >> y; p.push_back(make_pair(x, y));
    }
    ll c[100000] = {0};
    for (ll i = 0; i < n; i++) {
        bool cccc = check(a[i]);
        if (cccc) c[i+1] = c[i] + 1;
        else c[i+1] = c[i];
    }
    for (auto i : p) {
        cout << c[i.second] - c[i.first-1] << endl;
    }
}

