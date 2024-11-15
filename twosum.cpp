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
int s[5050];
 
int main() {
  int n;
  scanf("%d", &n);
  for (int i = 1; i <= n; ++i) {
    scanf("%d", a + i);
    s[i] = s[i - 1] + a[i];
  }
  int ans = 0;
  for (int i = 2; i <= n; ++i) {
    int x = 0;
    int l = 0;
    int r = s[i];
    for (int j = 1; j < i; ++j) {
      while (x + 1 < i && l < r) {
        ++x;
        l += a[x];
        r -= a[x];
      }
      if (l == r) ans = std::max(ans, i - j + 1);
      l -= a[j];        
    }
  }
  printf("%d", ans);
}

