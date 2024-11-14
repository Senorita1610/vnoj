#include<bits/stdc++.h>
#define int long long

using namespace std;
const int MAXN = 1e5+5;
const int INF = 1e9+7;
const int mod = 1e9+7;

struct edge { int u, v, w; }e[MAXN << 2];
struct node { int x, y, z, id; }a[MAXN];

int n, m, sum = 0;
int fa[MAXN];

int read() {
    int s = 0, f = 0;
    char ch = getchar();
    while(!isdigit(ch)) f |= (ch == '-'), ch = getchar();
    while(isdigit(ch)) s = (s << 1) + (s << 3) + ch - '0', ch = getchar();
    return f ? -s : s;
}

int find(int x) { return fa[x] == x ? x : fa[x] = find(fa[x]); }
int Dis(int x, int y) { return min(abs(a[x].x - a[y].x), min(abs(a[x].y - a[y].y), abs(a[x].z - a[y].z))); }
bool cmp1(node x, node y) { return x.x < y.x; }
bool cmp2(node x, node y) { return x.y < y.y; }
bool cmp3(node x, node y) { return x.z < y.z; }
bool cmp4(edge x, edge y) { return x.w < y.w; }

signed main()
{
    n = read();
    for(int i = 1; i <= n; ++i) a[i].x = read(), a[i].y = read(), a[i].z = read(), a[i].id = i;
    sort(a + 1, a + n + 1, cmp1);
    for(int i = 1; i < n; ++i) e[++m] = (edge){a[i].id, a[i + 1].id, Dis(i, i + 1)};
    sort(a + 1, a + n + 1, cmp2);
    for(int i = 1; i < n; ++i) e[++m] = (edge){a[i].id, a[i + 1].id, Dis(i, i + 1)};
    sort(a + 1, a + n + 1, cmp3);
    for(int i = 1; i < n; ++i) e[++m] = (edge){a[i].id, a[i + 1].id, Dis(i, i + 1)};
    sort(e + 1, e + m + 1, cmp4);
    for(int i = 1; i <= n; ++i) fa[i] = i;
    for(int i = 1, cnt = 0; i <= m; ++i) {
        int uf = find(e[i].u), vf = find(e[i].v);
        if(uf != vf) {
            fa[uf] = vf;
            sum += e[i].w;
            if(++cnt == n - 1) break;
        }
    }
    printf("%lld\n", sum);
    return 0;
}

