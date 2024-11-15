#include <cstdio>
#include <iostream>
#include <vector>
#include <bitset>
#include <cstring>

using namespace std;

const int max_size = 101;

vector < pair<int, int> > Bridge;
vector <int> adj[max_size];

bool fr[max_size];

int N, M, Time, Count, ans, t;
int dfs_low[max_size], dfs_num[max_size], nChild[max_size];

int dfs(int u, int p) {
        dfs_low[u] = dfs_num[u] = ++Time;
        Count = 1;

        for (int j = 0; j < adj[u].size(); j++) {
                int v = adj[u][j];
                if (v != p) {
                        Count++;
                        if (dfs_num[v]) dfs_low[u] = min(dfs_low[u], dfs_num[v]);
                        else {
                                Count += dfs(v, u);
                                dfs_low[u] = min(dfs_low[u], dfs_low[v]);
                                if (dfs_low[v] >= dfs_num[v])
                                    Bridge.push_back(make_pair(v, u));
                        }
                }
        }

        return Count;
}

void getChild(int u) {
        t++;
        fr[u] = true;
        for (int j = 0; j < adj[u].size(); j++) {
                int v = adj[u][j];
                if (!fr[v]) getChild(v);
        }
}

int main() {
        #ifndef ONLINE_JUDGE
                freopen("spoj.inp", "r", stdin);
        #endif

        cin >> N >> M;
        for (int i = 1; i <= M; i++) {
                int x, y;
                cin >> x >> y;
                adj[x].push_back(y);
                adj[y].push_back(x);
        }

        for (int i = 1; i <= N; i++)
                if (!dfs_num[i]) dfs(i, i);

        for (int i = 0; i < Bridge.size(); i++) {
                memset(fr, false, sizeof fr);
                t = 0;
                fr[Bridge[i].second] = true;
                getChild(Bridge[i].first);
                ans += t*(N-t);
        }

        cout << ans;

        return 0;
}

