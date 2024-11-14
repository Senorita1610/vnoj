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

struct edge {
  int to, ef;
  edge(int to, int ef) : to(to), ef(ef) { }
};

std::vector<edge> ed[N];

int mark[N];
long long ef[N];

struct cmp {
  bool operator()(int i, int j) {
    if (ef[i] == ef[j]) return i < j;
    return ef[i] < ef[j];
  }
};

std::set<int, cmp> myset;

int main() {
  int n, m, s;
  scanf("%d %d %d", &n, &m, &s);
  for (int i = 1; i <= m; ++i) {
    int u, v, c;
    scanf("%d %d %d", &u, &v, &c);
    ed[u].push_back(edge(v, c));
    ed[v].push_back(edge(u, c));
  }
  for (int i = 1; i <= n; ++i) {
    long long v = 0;
    for (int j = 0; j < ed[i].size(); ++j) {
      v += ed[i][j].ef;
    }
    ef[i] = v;
    myset.insert(i);
  }
  while (!myset.empty()) {
    int u = *myset.begin();
    if (ef[u] >= s) break;
    myset.erase(u);
    mark[u] = 1;
    for (int i = 0; i < ed[u].size(); ++i) {
      int v = ed[u][i].to;
      if (mark[v]) continue;
      myset.erase(v);
      ef[v] -= ed[u][i].ef;
      myset.insert(v);
    }
  }
  if (myset.empty()) {
    puts("-1");
  } else {
    printf("%d\n", myset.size());
    std::vector<int> vect(myset.begin(), myset.end());
    std::sort(vect.begin(), vect.end());
    for (int i = 0; i < vect.size(); ++i) {
      printf("%d ", vect[i]);
    }
  }
}

