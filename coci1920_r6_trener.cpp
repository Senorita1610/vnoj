#include<bits/stdc++.h>
using namespace std;
 
using ll = long long;
using ld = long double;
#define pb push_back
#define endl '\n'
#define fi first
#define se second
#define fio ios_base::sync_with_stdio(false);cin.tie(NULL);
#define CDIV(a,b) (((a)+(b)-(1))/(b))
const ll inf = 1e17 + 5;
const ll mod = 1e9 + 7;
const ll N = 1e3 + 30;
 
 
ll mod_(ll a, ll b)
{
    if(a >= 0)return a % b;
    a += (-a/b + 1) * b;
    return a % b;
}
 
void solve()
{
    ll n, k;
    cin >> n >> k;
    vector<vector<string> >v(n, vector<string>(k));
    vector<map<string, ll> >m(n);
    for(ll i = 0; i < n; ++i)
    {
        for(ll j = 0; j < k; ++j)
        {
            cin >> v[i][j];
            m[i][v[i][j]]++;
        }
    }
    vector<map<string, ll> >dp(n);
    for(ll i = 0; i < k; ++i)dp[n - 1][v[n - 1][i]]++;
 
    for(ll i = n - 1; i >= 1; --i)
    {
        for(auto p : dp[i])
        {
            //cout << p.fi << ' ' << p.se << endl;
            string tmp{p.fi.begin(), p.fi.end() - 1};
            if(m[i - 1].count(tmp))
            {
                //cout << i << ' ' << p.fi << ' ' << tmp << ' ' << p.se << endl;
                dp[i - 1][tmp] += m[i - 1][tmp] * p.se % mod;
                dp[i - 1][tmp] %= mod;
            }
            if(tmp != string{p.fi.begin() + 1, p.fi.end()})
            {
                tmp = string{p.fi.begin() + 1, p.fi.end()};
                //cout << i << ' ' << p.fi << ' ' << tmp << ' ' << p.se << endl;
                if(m[i - 1].count(tmp))
                {
                    //cout << i << ' ' << p.fi << ' ' << tmp << ' ' << p.se << endl;
                    dp[i - 1][tmp] += m[i - 1][tmp] * p.se % mod;
                    dp[i - 1][tmp] %= mod;
                }
            }
        }
    }
 
    ll ans = 0;
    for(auto p : dp[0])
    {
        //cout << p.fi << ' ' << p.se << endl;
        ans += p.se;
        ans %= mod;
    }
    cout << ans << endl;
    
    
 
}
    
int main()
{
    fio;
    //ll t; cin >> t; while(t--)
    {
        solve();
    }
}

