#include <algorithm>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <map>
#include <set>
#include <string>
#include <vector>
 
char s[2020202];
 
int main() {
  int tt;
  scanf("%d", &tt);
  while (tt--) {
    int n;
    scanf("%d", &n);
    int c = 0;
    int d = 0;
    for (int i = 1; i <= n; ++i) {
      int t = i + c;
      s[++d] = t % 10 + '0';
      c = t / 10;
    }
    for (int i = n - 1; i >= 1; --i) {
      int t = i + c;
      s[++d] = t % 10 + '0';
      c = t / 10;
    }
    if (c) s[++d] = c;
    s[d + 1] = 0;
    std::reverse(s + 1, s + d + 1);
    puts(s + 1);
  }
}

