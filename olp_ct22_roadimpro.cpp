#include <bits/stdc++.h>
using namespace std;

#define Fname ((string) "test")
#define int long long
#define ii pair <int, int>
#define iii pair <int, ii>
#define fi first
#define se second
#define endl '\n'
const int N = 2005;
const int INF = 1e9 + 7;

int n, m, q, d[N][2];
vector <ii> a[N];

void dijkstra(int u) {
    priority_queue <iii, vector <iii>, greater <iii>> pq;
    for (int i = 1; i <= n; i++)
        d[i][0] = d[i][1] = INF;
    d[u][0] = d[u][1] = 0;
    pq.push({0, {0, u}});
    while (pq.size()) {
        u = pq.top().se.se;
        int du = pq.top().fi, state = pq.top().se.fi;
        pq.pop();
        if (du != d[u][state])
            continue;
        for (ii e : a[u]) {
            int v = e.se, w = e.fi;
            if (d[v][state] > du + w) {
                d[v][state] = du + w;
                pq.push({du + w, {state, v}});
            }
            if (!state) {
                if (d[v][1] > du) {
                    d[v][1] = du;
                    pq.push({du, {1, v}});
                }
            }
        }
    }
}

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
    cin >> n >> m >> q;
    for (int i = 1; i <= m; i++) {
        int u, v, w; cin >> u >> v >> w;
        a[u].push_back({w, v});
    }
    dijkstra(1);
    while (q--) {
        int s, t0; cin >> s >> t0;
        cout << min(d[s][0], d[s][1] + t0) << endl;
    }
	return 0;
}

