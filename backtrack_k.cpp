#include <bits/stdc++.h>
#define int long long
using namespace std;
const int maxn = 20; 
const int inf = LLONG_MAX / 100; 

int n; 
int h[maxn]; 
int w[maxn][maxn]; 

signed main() { 
    cin >> n; 
    for (int i = 0; i < n; i++) cin >> h[i]; 
    for (int i = 0; i < n; i++) for(int j = i + 1; j < n; j++) cin >> w[i][j]; 
    int ans = inf; 
    for (int mask = 0; mask < (1 << n); mask++) { 
        int sum = 0; 
        for (int i = 0; i < n; i++) { 
            int bit_i = mask >> i & 1; 
            sum += (bit_i * 2 - 1) * h[i];
        }
        for (int i = 0; i < n; i++) { 
            for (int j = i + 1; j < n; j++) { 
                int bit_i = mask >> i & 1; 
                int bit_j = mask >> j & 1; 
                sum += (bit_i * 2 - 1) * (bit_j * 2 - 1) * w[i][j];
            }
        }
        ans = min(ans, sum); 
    }
    cout << ans << endl; 
}

