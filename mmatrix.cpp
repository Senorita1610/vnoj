#include <bits/stdc++.h>

using namespace std;

const int N = 7;
const int inf = int(1e9);

int n, a[N][N][N], M, c[N];

void cal(int i) {
    if (i == n) {
        int tmp = -inf;
        for(int j = 0; j < n; j++) tmp = max(tmp, c[j]);
        M = min(M, tmp);
        return;
    }
    for(int k = 0; k < n; k++) {
        for(int j = 0; j < n; j++) c[j] += a[k][i][j];
        cal(i+1);
        for(int j = 0; j < n; j++) c[j] -= a[k][i][j];
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    while (1) {
        cin >> n;
        if (n == -1) break;
        for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++) cin >> a[0][i][j];

        for(int k = 1; k < n; k++)
            for(int i = 0; i < n; i++) {
                for(int j = 1; j < n; j++) a[k][i][j] = a[k-1][i][j-1];
                a[k][i][0] = a[k-1][i][n-1];
            }

        M = inf;
        cal(0);
        cout << M << "\n";
    }
}

