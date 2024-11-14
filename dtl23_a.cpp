#include<bits/stdc++.h>
#define int                     long long
#define double                  long double
#define forUp(i, l, r, step)    for(int i = l; i <= r; i += step)
#define forDown(i, l, r, step)  for(int i = l; i >= r; i += step)
#define forEach(it, v)          for(typeof((v).begin()) it = (v).begin(); it != (v).end(); it++)

using namespace std;

const int N     = 1e5 + 5;
const int MOD   = 1e9 + 7;
const int INF   = 0x3f3f3f3f3f3f3f3f;

int q, n;
bool check;

int binaryExponentiation(int a, int n){
    int res = 1;
    for (; n; n >>= 1, a *= a){
        if (n & 1) res *= a;
    }
    return res;
}

void solve(){
    cin >> n;
    if (abs(n) == 1) cout << "Piccolo\n";
    else{
        check = false;
        if (n < 0){
            check = true;
            n = -n;
        }
        forUp(i, 2, 55, 1){
            int tmp = pow(n, 1.0 / i);
            while (binaryExponentiation(tmp, i) < n) tmp++;
            while (binaryExponentiation(tmp, i) > n) tmp--;
            if (binaryExponentiation(tmp, i) == n){
                if (!check || (check && (i % 2))){
                    cout << "Piccolo\n";
                    return;
                }
            }
        }
        cout << "Majin Buu\n";    
    }
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> q;
    while (q--) solve();
}

