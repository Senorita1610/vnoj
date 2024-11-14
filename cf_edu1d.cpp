#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> ii;
typedef pair<int, ii> iii;
typedef long long ll;
typedef long double ld;

const ll infLL = 2e18 + 7;
const int inf = 2e9 + 7;
const int maxN = 200010;
const ll MOD = 998244353;
const double eps = 1e-12;

void solve()
{
    int n, m; cin >> n >> m;
    int k; cin >> k;

    vector<vector<int>> a(n, vector<int>(m, 0));

    char c;
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < m; ++j)
        {
            cin >> c;
            a[i][j] = (c == '*' ? 0 : 1);
        }
    }

    vector<vector<int>> visited(n, vector<int>(m, 0));
    vector<int> sz;

    auto bfs = [&](int x, int y, int idx)
    {
        auto check = [&](int u, int v)
        {
            return (bool)(u >= 0 && v >= 0 && u < n && v < m);
        };

        int td[4] = {1, -1, 0, 0};
        int tc[4] = {0, 0, -1, 1};

        queue<ii> q;
        int cnt = 0;

        q.push(ii(x, y));
        visited[x][y] = idx;

        while (q.size())
        {
            int ux = q.front().first;
            int uy = q.front().second;
            q.pop();

            visited[ux][uy] = idx;

            for (int k = 0; k < 4; ++k)
            {
                int vx = ux + td[k];
                int vy = uy + tc[k];

                if (!check(vx, vy)) continue;
            
                if (a[vx][vy] && !visited[vx][vy])
                {
                    q.push(ii(vx, vy));
                    visited[vx][vy] = idx;
                }
                if (!a[vx][vy]) cnt++;
            }
        }

        sz.push_back(cnt);
    };

    int cnt = 0;
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < m; ++j)
        {
            if (!visited[i][j] && a[i][j]) bfs(i, j, ++cnt);
        }
    }
    for (int i = 0; i < k; ++i)
    {
        int u, v; cin >> u >> v; u--, v--;
        cout << sz[visited[u][v] - 1] << '\n';
    }
}

int main()
{
    solve();
}

