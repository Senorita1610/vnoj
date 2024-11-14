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

int s[N], a[N];

int main() {
 int tt;
 for (scanf("%d", &tt); tt--; ) {
   int n;
   scanf("%d", &n);
   int v = 0;
   for (int i = 1; i <= n; ++i) scanf("%d", s + i);
   for (int i = 1; i <= n; ++i) scanf("%d", a + i);
   for (int i = 1; i <= n; ++i) v ^= s[i] % (a[i] + 1);
   puts(v ? "Jerry" : "Tom");
 }
}

