#include <bits/stdc++.h>
using namespace std;

#define int long long
const int MOD = 1e9 + 7;
const int N = 5e3 + 3;
#define line vector <int>
#define matrix vector <line>

matrix f, B;

int conv(int n, int k) {
    if (n >= 0)
        return n;
    return k + n;
}

matrix mul(const matrix &A, const matrix &B) {
    int m = A.size(), p = A[0].size(), n = B[0].size();
    matrix C(m, line(n, 0));
    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
            for (int k = 0; k < p; k++)
                (C[i][j] += A[i][k] * B[k][j]) %= MOD;
    return C;
}

matrix Pow(const matrix A, int n) {
    if (n == 1)
        return A;
    matrix res = Pow(A, n / 2);
    res = mul(res, res);
    return (n & 1 ? mul(res, A) : res);
}

signed main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int m, k;
    cin >> m >> k;
    f.resize(k), B.resize(k);
    for (int i = 0; i < k; i++)
        f[i].push_back(0), B[i].resize(k);
    f[0][0] = 1;
    for (int i = 0; i < k; i++) {
        B[i][i] = 1;
        B[i][conv(i - 1, k)] = 3;
        B[i][conv(i - 2, k)] = 3;
    }
    cout << (mul(Pow(B, m), f)[0][0] - 1 + MOD) % MOD;
    return 0;
}

