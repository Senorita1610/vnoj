#include <algorithm>
#include <bitset>
#include <cassert>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <ctime>
#include <deque>
#include <functional>
#include <iomanip>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <sstream>
#include <string>
#include <vector>

const int N = 100010;

namespace dsu {
  
struct persist {
  int u, p, r;
  persist() { }
  persist(int u, int p, int r) : u(u), p(p), r(r) { }
} stack[N];
  
int sz, parent[N], rank[N];

inline int find(int x) {
  while (x != parent[x]) {
    x = parent[x];
  }
  return x;
}

inline void join(int u, int v) {
  u = find(u);
  v = find(v);
  if (u == v) return;
  if (rank[u] < rank[v]) std::swap(u, v);    
  stack[++sz] = persist(v, parent[v], rank[u]);
  parent[v] = u;
  if (rank[u] == rank[v]) {
    ++rank[u];
  }
}

inline void rollback(int limit) {
  while (sz > limit) {
    int u = stack[sz].u;
    rank[parent[u]] = stack[sz].r;
    parent[u] = stack[sz].p;
    --sz;
  }
}

}; 

char ans[N];
int an, qt[N << 1], qu[N << 1], qv[N << 1], pos[N << 1];

typedef std::pair<int, int> edge;
typedef std::map<edge, int>::iterator ite;

std::map<edge, int> last, have;

void solve(int f, int t) {
  if (f == t) {
    if (qt[f] == 3) {
      ans[++an] = (dsu::find(qu[f]) == dsu::find(qv[f])) + '0';
    }
    return;
  }
  int m = (f + t) >> 1;
  int old = dsu::sz;
  for (int i = m + 1; i <= t; ++i)
    if (pos[i] > 0 && pos[i] < f) {
//      assert(qt[i] == 2);
      dsu::join(qu[i], qv[i]);
    }
  solve(f, m);
  dsu::rollback(old);
  for (int i = f; i <= m; ++i)
    if (pos[i] > 0 && pos[i] > t) {
      dsu::join(qu[i], qv[i]);
    }
  solve(m + 1, t);
  dsu::rollback(old);
}

int main() {
  int n, m;
  scanf("%d %d", &n, &m);
  for (int i = 1; i <= m; ++i) {
    scanf("%d %d %d", qt + i, qu + i, qv + i);
    if (qu[i] == qv[i]) continue;
    if (qu[i] > qv[i]) std::swap(qu[i], qv[i]);
    if (qt[i] != 3) {
      edge e(qu[i], qv[i]);      
      if (qt[i] == 1) {
        int h = have[e]++;
        if (h == 0) last[e] = i;
      } else if (have.find(e) != have.end()) {
        int h = --have[e];
        if (h == 0) {
          int z = last[e];
          pos[z] = i;
          pos[i] = z;
          have.erase(e);
          last.erase(e);
        }
      }
    }
  }
  for (ite i = last.begin(); i != last.end(); ++i) {
    pos[i->second] = ++m;
    pos[m] = i->second;
    qu[m] = qu[i->second];
    qv[m] = qv[i->second];
  }
  for (int i = 1; i <= n; ++i) {
    dsu::parent[i] = i;
  }
  solve(1, m);
  puts(ans + 1);
}

