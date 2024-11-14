#pragma GCC optimize("O2", "O3", "Ofast")
#pragma target("avx", "avx2", "fma")
#include <bits/stdc++.h>
#define int long long
#define double long double
#define task "test"
#define forUp(i, l, r, step) for(int i = l; i <= r; i += step)
#define forDown(i, l, r, step) for(int i = l; i >= r; i += step)
#define forEach(it, v) for(typeof v.begin() it = v.begin(), _e = v.end(); it != _e; it++)
#define gcd(a, b) __gcd(a, b)
#define lcm(a, b) a / gcd(a, b) * b

using namespace std;

const int N   = 5e2 + 2;
const int LIM = 9e5 + 5;
const int MOD = 1e3 + 7;

int n, a[N][N], l, r, m, res;
bool visited[N][N];
int di[] = {-1, 0, 0, 1};
int dj[] = {0, -1, 1, 0};

void DFS(int i, int j, int m){
    visited[i][j] = true;
    if (visited[n][n]) return;
    forUp(k, 0, 3, 1){
        int i1 = i + di[k];
        int j1 = j + dj[k];
        if (i1 >= 1 && i1 <= n && j1 >= 1 && j1 <= n && abs(a[i][j] - a[i1][j1]) <= m && !visited[i1][j1]) DFS(i1, j1, m);
    }
}

bool f(int m){
    memset(visited, false, sizeof visited);
    DFS(1, 1, m);
    return visited[n][n];
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    forUp(i, 1, n, 1) forUp(j, 1, n, 1) cin >> a[i][j];
    l = 0;
    r = 1e6;
    while (r - l >= 0){
        m = l + r >> 1;
        if (f(m)){
            res = m;
            r = m - 1;
        }
        else l = m + 1;
    }
    cout << res;

    return (0 ^ 0);
}

