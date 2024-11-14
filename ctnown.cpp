#include <bits/stdc++.h>
using namespace std;

using ll = unsigned long long;
bitset <1000> sieve;
const int N = 350;
ll dp[N + 1][100];
int t, n, x, prime[100];

void p_sieve(){
    for (int i = 2; i * i <= N; i++)
        if (!sieve[i])
            for (int j = i * i; j <= N; j += i)
                sieve[j] = true;
    for (int i = 2; i <= N; i++)
        if (!sieve[i]) prime[++n] = i;
}

void pre_calc(){
    p_sieve();
    for (int j = 0; j <= n; j++)
        dp[0][j] = 1;
    for (int i = 1; i <= N; i++){
        dp[i][0] = 1;
        for (int j = 1; j <= n; j++){
            dp[i][j] = dp[i][j - 1];
            int power = 1;
            for (; power <= i; power *= prime[j])
                dp[i][j] = max(dp[i][j], dp[i - power][j - 1] * power);
        }
    }
}

int main(){
    pre_calc(); cin >> t;
    while (t--){
        cin >> x; cout << dp[x][n] << '\n';
    }
}

