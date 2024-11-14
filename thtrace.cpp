#include <bits/stdc++.h>
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define REP(i, a, b) for (int i = (a); i <= (b); ++i)
#define X first
#define Y second
#define VI vector<int>
#define endl '\n'

const int N = 1010;

using namespace std;

typedef pair<int, int> II;

int n, timer, m, nTest;
VI a[N];
int low[N], num[N], dx[N], dy[N];
bool inCycle[N], was[N];
II test[N];

void dfs(int u, int par) {
  num[u] = ++timer; low[u] = N;
  for (int v: a[u])
  if (v != par) {
    if (num[v]) {
      low[u] = min(low[u], num[v]);
    } else {
      dfs(v, u);
      low[u] = min(low[u], low[v]);
    }
  }
  inCycle[u] = low[u] <= num[u];
}

void bfs(int source, int d[]) {
  REP(i, 1, n) was[i] = d[i] = 0;
  queue<int> Q;
  Q.push(source); was[source] = 1;
  while (!Q.empty()) {
    int u = Q.front(); Q.pop();
    for (auto v: a[u])
    if (!was[v]) {
      was[v] = 1;
      d[v] = d[u] + 1;
      Q.push(v);
    }
  }
}

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  #ifdef _LAD_
    freopen("THTRACE.in", "r", stdin);
  #endif // _LAD_
  cin >> n >> m >> nTest;
  FOR(i, 0, nTest) cin >> test[i].X >> test[i].Y;
  int u, v;
  FOR(i, 0, m) {
    cin >> u >> v;
    a[u].push_back(v);
    a[v].push_back(u);
  }
  REP(i, 1, n)
  if (!num[i]) dfs(i, 0);
  FOR(i, 0, nTest) {
    bfs(test[i].X, dx);
    bfs(test[i].Y, dy);
    bool canEscape = 0;
    REP(i, 1, n)
    if (inCycle[i]) {
      canEscape |= dx[i] > dy[i];
      if (canEscape) break;
    }
    cout << !canEscape << endl;
  }
  return 0;
}

