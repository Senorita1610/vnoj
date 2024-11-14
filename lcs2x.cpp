#include <algorithm>
#include <cassert>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <map>
#include <set>
#include <sstream>
#include <string>
#include <vector>
 
#define m2 std::make_pair
 
typedef std::pair<int, int> p2;
 
int a[1515], b[1515], c[1515];
 
int main() {
  int tt;
  scanf("%d", &tt);
  while (tt--) {
    memset(c, 0, sizeof(c));
    int m, n;
    scanf("%d %d", &m, &n);
    for (int i = 1; i <= m; ++i)
      scanf("%d", a + i);
    for (int i = 1; i <= n; ++i)
      scanf("%d", b + i);
    int ans = 0;
    for (int i = 1; i <= m; ++i) {
      int val = 0;
      for (int j = 1; j <= n; ++j) {
        int val_t = val;
        if ((b[j] << 1) <= a[i])
          val = std::max(val, c[j]);
        if (a[i] == b[j])
          c[j] = std::max(c[j], val_t + 1);
      }
    }
    for (int i = 1; i <= n; ++i)
      ans = std::max(ans, c[i]);
    printf("%d\n", ans);
  }
}

