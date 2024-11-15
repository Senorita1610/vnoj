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
 
const int mod = 1e9;
 
int a[101][101], dp[101][101];
 
int main() {
  int n, m;
  scanf("%d %d", &n, &m);
  for (int i = 1; i <= n; ++i)
    dp[i][1] = 1;
  for (int p = 1; p <= n; ++p) {
    for (int q = 1; q <= m; ++q) {
      scanf("%d", a[p] + q);
      for (int i = 1; i <= p; ++i)
        for (int j = 1; j <= q; ++j)
          if (i + j < p + q && j < m) {
            if (std::__gcd(a[i][j], a[p][q]) > 1)
              dp[p][q] += dp[i][j];
            if (dp[p][q] >= mod) dp[p][q] -= mod;
          }
    }
  }
  int ans = 0;
  for (int i = 1; i <= n; ++i) {
    ans += dp[i][m];
    if (ans >= mod) ans -= mod;
  }
  printf("%d", ans);
}

