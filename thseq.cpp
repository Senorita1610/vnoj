#include <bits/stdc++.h>
using namespace std;

const int BASE = (int)1e6;
const int MAX_N = 2500 + 1;
const int MAX_V = (int)1e7;

int n, arr[MAX_N];

void Input() {
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> arr[i];
}

int f[MAX_V];
int dp[MAX_N][MAX_N];

void Process() {
    memset(f, 0, sizeof f);

    for (int i = 1; i + 1 <= n; i++) for (int j = i + 1; j <= n; j++) dp[i][j] = 2;

    for (int i = 1; i + 1 <= n; i++) {
        for (int j = i + 1; j <= n; j++) {
            int temp = f[arr[j] - arr[i] + BASE];

            if (1 <= temp && temp <= i - 1) dp[i][j] = dp[temp][i] + 1;
        }

        f[arr[i] + BASE] = i;
    }

    int result = 0;
    for (int i = 1; i + 1 <= n; i++) for (int j = i + 1; j <= n; j++) result = max(result, dp[i][j]);
    cout << result << '\n';
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int t; cin >> t; while (t--) {
        Input();

        Process();
    }

    return 0;
}

