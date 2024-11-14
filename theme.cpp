#include <algorithm>
#include <cassert>
#include <cmath>
#include <cstdio>
#include <cstring>
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
 
int a[5050];
int lcp[5050][5050];
 
int main() {
  int n, last;
  scanf("%d %d", &n, &last);
  for (int i = 1, v; i < n; ++i) {
    scanf("%d", &v);
    a[i] = v - last;
    last = v;
  }
  int ans = 0;
  for (int i = 1; i < n; ++i)
    for (int j = i + 1; j < n; ++j) {
      if (a[i] == a[j]) {
        lcp[i][j] = lcp[i - 1][j - 1] + 1;
        int v = std::min(lcp[i][j], j - i - 1);
        if (v > ans) ans = v;
      }
    }
  fprintf(stderr, "ans = %d\n", ans);
  printf("%d", ans >= 4 ? ans + 1 : 0);
}

