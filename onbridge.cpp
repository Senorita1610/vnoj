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
#include <numeric>
#include <queue>
#include <set>
#include <sstream>
#include <string>
#include <vector>
 
#define DEBUG(z, x) { cerr << setw(z) << "" << (#x) << " = " << (x) << '\n'; }
 
using namespace std;
 
const int N = 50010;
 
int n, pos, bridges, parent[N], comp[N], cyc[N], rank[N], mark[N];
 
void init() {
  bridges = 0;
  for (int i = 1; i <= n; ++i) {
    parent[i] = 0;
    comp[i] = cyc[i] = i;
    rank[i] = 0;
  }  
}
 
int find_cyc(int u) {
  if (cyc[u] != u) cyc[u] = find_cyc(cyc[u]);
  return cyc[u];
}
 
int find_comp(int u) {
  if (comp[u] != u) comp[u] = find_comp(comp[u]);
  return comp[u];
}
 
void compress(int u, int v) {
  ++pos; 
  int lca = 0;
  static int u_path[N], v_path[N];
  int u_sz = 0, v_sz = 0;
  for (;;) {
    if (u) {
      u = find_cyc(u);
      u_path[++u_sz] = u;
      if (mark[u] == pos) {
        lca = u;
        break;
      }
      mark[u] = pos;
      u = parent[u];
    }
    if (v) {
      v = find_cyc(v);
      v_path[++v_sz] = v;
      if (mark[v] == pos) {
        lca = v;
        break;
      }
      mark[v] = pos;
      v = parent[v];
    }        
  }
  for (int i = 1; i <= u_sz; ++i) {
    int x = u_path[i];
    cyc[x] = lca;
    if (x == lca) break;
    --bridges;
  }
  for (int i = 1; i <= v_sz; ++i) {
    int x = v_path[i];
    cyc[x] = lca;
    if (x == lca) break;
    --bridges;
  }
}
 
void reroot(int u) {
  u = find_cyc(u);
  int root = u;
  int child = 0; 
  int depth = 0;
  while (u) {
    int p = find_cyc(parent[u]);
    parent[u] = child;
    comp[u] = root;
    child = u;
    u = p;
    ++depth;
  }
  rank[root] = max(rank[root], depth);
}
 
void add_edge(int u, int v) {
  u = find_cyc(u);
  v = find_cyc(v);
  if (u == v) {
    return;
  }
  int uid = find_comp(u);
  int vid = find_comp(v);
  if (uid != vid) {
    ++bridges;    
    if (rank[uid] > rank[vid]) {
      swap(u, v);
      swap(uid, vid);
    }
    reroot(u);
    parent[u] = v;
    comp[u] = v;
    rank[vid] += rank[vid] == rank[u];
  } else {
    compress(u, v);
  }
}
 
int main() {
  int tt;
  scanf("%d", &tt);
  while (tt--) {
    int m;
    scanf("%d %d", &n, &m);
    init();
    while (m--) {
      int u, v;
      scanf("%d %d", &u, &v);
      ++u, ++v;
      add_edge(u, v);      
      printf("%d\n", bridges);
    }
  }
}

