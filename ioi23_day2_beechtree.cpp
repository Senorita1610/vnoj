#include <bits/stdc++.h>
 
using namespace std;
 
vector<int> beechtree(int n, int m, vector<int> P, vector<int> C) {
  vector<vector<int>> g(n);
  for (int i = 1; i < n; i++) g[P[i]].push_back(i);
  for (int i = 0; i < n; i++) sort(g[i].begin(), g[i].end(), [&](int u, int v){ return C[u] < C[v]; });
  vector<int> sub(n);
  for (int i = n - 1; i >= 0; i--) {
    sub[i] = 1;
    for (int j : g[i]) sub[i] += sub[j];
  }
  vector<int> heavy(n);
  for (int i = 0; i < n; i++) {
    heavy[i] = -1;
    for (int j : g[i]) {
      if (heavy[i] == -1 || sub[heavy[i]] < sub[j]) heavy[i] = j;
    }
  }
 
  vector<int> ret(n, -1);
  vector<set<pair<int, int>>> res(n);
 
  for (int v = n - 1; v >= 0; v--) {
    if (heavy[v] == -1) {
      ret[v] = 1;
      res[v].insert({sub[v], v});
      continue;
    }
    for (int i : g[v]) {
      assert(ret[i] != -1);
      if (ret[i] == 0) {
        ret[v] = 0;
        break;
      }
    }
    for (int i = 0; i < (int) g[v].size() - 1; i++) {
      if (C[g[v][i]] == C[g[v][i + 1]]) {
        ret[v] = 0;
        break;
      }
    }
    if (ret[v] == 0) continue;
    auto is_cover = [&](int big, int small) {
      if (g[big].size() < g[small].size()) return false;
      int id = 0;
      for (int i = 0; i < (int) g[small].size(); i++) {
        while (id < (int) g[big].size() && C[g[big][id]] != C[g[small][i]]) id++;
        if (id == (int) g[big].size()) return false;
        int B = g[big][id], S = g[small][i];
        if (sub[B] < sub[S]) return false;
      }
      return true;
    };
    swap(res[v], res[heavy[v]]);
    for (int u : g[v]) {
      if (u == heavy[v]) continue;
      vector<int> order;
      for (auto [_, nd] : res[u]) order.push_back(nd);
      for (int nd : order) {
        auto R = res[v].lower_bound(make_pair(sub[nd], -1));
        if (R == res[v].end() || R->first > sub[nd]) {
          if (R != res[v].end()) {
            if (!is_cover(R->second, nd)) {
              ret[v] = 0;
              break;
            }
          }
          if (R != res[v].begin()) {
            auto L = prev(R);
            if (!is_cover(nd, L->second)) {
              ret[v] = 0;
              break;
            }
          }
          res[v].insert(make_pair(sub[nd], nd));
        } else {
          assert(R->first == sub[nd]);
          if (!is_cover(R->second, nd) || !is_cover(nd, R->second)) {
            ret[v] = 0;
            break;
          }
        }
      }
      if (ret[v] == 0) break;
    }
    if (ret[v] != 0 && res[v].size()) {
      int nxt = prev(res[v].end())->second;
      if (!is_cover(v, nxt)) {
        ret[v] = 0;
      }
    }
    if (ret[v] == 0) {
      res[v].clear();
    } else {
      ret[v] = 1;
      res[v].insert(make_pair(sub[v], v));
    }
  }
  return ret;
}

