#include<bits/stdc++.h>
#define ll long long

using namespace std;

// Hàm tính U?c Chung L?n Nh?t (GCD)
ll gcd(ll a, ll b){
    while (b)
    {
        ll t = b;
        b = a % b;
        a = t;
    }
    return a;
}

// Hàm tính B?i Chung Nh? Nh?t (LCM)
ll lcm(ll a, ll b, ll N){
    if(a == -1 || b == -1)
        return -1;
    ll c = gcd(a,b);
    if(b/c > N/a)   return -1;
    return a / c * b;
}

ll preResult (ll a, ll b){
    if(b==-1){
        return 0;
    }
    if(a%b != 0){
        return 0;
    }

    ll ans = a/b;
    ll res = 0;
    for (ll  i = 1; i*i <= ans; i++)
    {
        if(ans%i == 0){
            if(i*i == ans){
                res++;
            }
            else{
                res += 2;
            }
        }
    }
    return res;
}

void solve(){
    ll n, a, b, c;
    cin >> n >> a >> b >> c;

    // Tính BCNN c?a các c?p
    ll lcm_ab = lcm(a, b, n);
    ll lcm_ac = lcm(a, c, n);
    ll lcm_bc = lcm(b, c, n);
    ll lcm_abc = lcm(lcm_ab,c,n);

    // Ð?m s? lu?ng s? chia h?t cho ít nh?t hai trong ba s?
    ll result = 0;
    // L?p qua t?t c? các s? t? 1 d?n sqrt(n)
    
    result = preResult(n,lcm_ab) + preResult(n,lcm_ac) + preResult(n,lcm_bc) - 2 * preResult(n,lcm_abc);
    // Xu?t k?t qu?
    cout << result << endl;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    solve();

    return 0;
}

