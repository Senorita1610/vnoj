#include <bits/stdc++.h>
#define int long long
using namespace std;
int f[501][501];
int R[501][501], C[501][501];
bool ok(int x, int y)
{
    if (x <= 0 || y <= 0)
        return false;
    if (f[x][y] != -1)
        return f[x][y];
    f[x][y] = 0;
    if (!ok(x - 1, y) && R[x][y] % 2 == 0)
        f[x][y] = 1;
    if (!ok(x, y - 1) && C[y][x] % 2 == 0)
        f[x][y] = 1;
    return f[x][y];
}
void solve()
{
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
        {
            int a;
            cin >> a;
            R[i][j] = R[i][j - 1] + a;
            C[j][i] = C[j][i - 1] + a;
        }
    memset(f, -1, sizeof(f));
    if (ok(n, n))
        cout << "YES" << endl;
    else
        cout << "NO" << endl;
}
int32_t main()
{
    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
}

