#include <bits/stdc++.h>
#define int long long
#define II pair<int, int>
#define fi first
#define se second
using namespace std;
const int maxn = 2e5 + 1, inf = 1e9 + 1;
struct nodes
{
    int u, v, w;
} ed[maxn];
vector<II> gr[maxn];
int rt[maxn], ck[maxn];
bool cmp(nodes a, nodes b)
{
    return a.w > b.w;
}

int root(int u)
{
    if (u == rt[u])
        return u;
    return (rt[u] = root(rt[u]));
}
bool join(int u, int v, int w)
{
    int uu = root(u), vv = root(v);
    if (uu == vv)
        return false;
    gr[u].push_back({v, w});
    gr[v].push_back({u, w});
    rt[uu] = vv;
    return true;
}

struct Nnode
{
    int p, minn = inf;
} up[maxn][30];
int depth[maxn];
void dfs(int u, int par, int to)
{
    depth[u] = depth[par] + 1;
    up[u][0].p = par;
    up[u][0].minn = to;
    for (int i = 1; i <= 20; i++)
    {
        up[u][i].p = up[up[u][i - 1].p][i - 1].p;
        up[u][i].minn = min(up[up[u][i - 1].p][i - 1].minn, up[u][i - 1].minn);
    }
    for (auto v : gr[u])
        if (v.fi != par)
            dfs(v.fi, u, v.se);
}

int lca(int u, int v)
{
    if (depth[u] < depth[v])
        swap(u, v);
    for (int i = 20; i >= 0; i--)
    {
        if (depth[up[u][i].p] >= depth[v])
            u = up[u][i].p;
    }
    if (u == v)
        return u;
    for (int i = 20; i >= 0; i--)
    {
        if (up[u][i].p != up[v][i].p)
            u = up[u][i].p, v = up[v][i].p;
    }
    return up[u][0].p;
}
int dist(int u, int v)
{
    return depth[u] + depth[v] - 2 * depth[lca(u, v)];
}
int calc(int u, int v)
{
    int res = inf;
    int par = lca(u, v);
    while (u != par)
    {
        int d = dist(u, par);
        int tmp = 1, cnt = 0;
        while (tmp * 2 <= d)
            tmp *= 2, cnt++;
        res = min(res, up[u][cnt].minn);
        u = up[u][cnt].p;
    }
    u = v;
    while (u != par)
    {
        int d = dist(u, par);
        int tmp = 1, cnt = 0;
        while (tmp * 2 <= d)
            tmp *= 2, cnt++;
        res = min(res, up[u][cnt].minn);
        u = up[u][cnt].p;
    }
    return res;
}
int32_t main()
{
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        rt[i] = i;
    for (int i = 1; i <= m; i++)
    {
        cin >> ed[i].u >> ed[i].v >> ed[i].w;
    }
    sort(ed + 1, ed + 1 + m, cmp);
    for (int i = 1; i <= m; i++)
    {
        int u = ed[i].u, v = ed[i].v, w = ed[i].w;
        ck[i] = join(u, v, w);
    }

    dfs(1, 0, 0);
    int ans = 0;
    for (int i = 1; i <= m; i++)
    {
        if (!ck[i])
        {
            int u = ed[i].u, v = ed[i].v;
            ans += calc(u, v) - ed[i].w;
        }
    }
    cout << ans << endl;
}

