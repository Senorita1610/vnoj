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
 
typedef std::pair<long long, int> p2;
 
p2 b[50505];
int a[50505];
 
int main() {
  int n, p;
  scanf("%d %d", &n, &p);
  for (int i = 1; i <= n; ++i) {
    scanf("%d", a + i);
    b[i].first = b[i - 1].first + a[i];
    b[i].second = i;
  }
  std::sort(b, b + n + 1);
  int ans = -1;
  int pos = n;
  int l = 0, r = 0;
  while (r <= n) {
    while (l <= n && b[r].first - b[l].first >= p) {
      if (b[l].second < pos) pos = b[l].second;
      ++l;
    }
    if (pos < b[r].second)
      if (ans == -1 || b[r].second - pos > ans)
        ans = b[r].second - pos;
    ++r;
  }
  printf("%d", ans);
}

