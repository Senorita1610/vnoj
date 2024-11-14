#include<bits/stdc++.h>
#define int long long
#define Int int
#define For(i,l,r) for(int i=l;i<=r;++i)
#define FOR(i,r,l) for(int i=r;i>=l;--i)

using namespace std;

const int N = 1e5 + 10;

int B, n, d, m;

namespace Solve1 {
  int a[N], q[N], h = 1, t = 0, ans = 0;
  void work() {
    For(i,1,n) cin >> a[i];
    sort(a + 1, a + n + 1);
    For(i,1,n) {
      while(t - h + 1 > 0 && a[i] - a[q[h]] > d) h++;
      ans += (t - h + 1);
      q[++t] = i;
    }
    cout << ans << '\n';
  }
}

namespace Solve2 {
  struct Node {
    int x, y;
  } a[N];
  int q[N], h = 1, t = 0, Ans = 0;
  
  Int T[N * 2] = {0};
  
  bool cmp(Node x, Node y) {
    return (x.x == y.x ? x.y < y.y : x.x < y.x);
  }

  int lb(int x) {
    return x & -x;
  }

  void add(int x, int k) {
    for (int i = x; i <= 2 * m; i += lb(i)) {
      T[i] += k;
    }
  }

  int ask(int x) {
    int ans = 0;
    for (int i = min(2 * m, x); i; i -= lb(i)) {
      ans += T[i];
    }
    return ans;
  }

  void work() {
    For(i,1,n) cin >> a[i].x >> a[i].y;
    For(i,1,n) {
      int x = (a[i].x - a[i].y), y = (a[i].x + a[i].y);
      a[i].x = x, a[i].y = y;
    }
    sort(a + 1, a + n + 1, cmp);
    For(i,1,n) {
      while(t - h + 1 > 0 && a[i].x - a[q[h]].x > d) {
        add(a[q[h]].y, -1);
        h++;
      }
      Ans += (ask(a[i].y + d) - ask(max(0ll, a[i].y - d - 1)));
      add(a[i].y, 1);
      q[++t] = i;
    }
    cout << Ans << '\n';
  }
}

namespace Solve3 {
  const int L = 76;

  struct Node {
    int x, y, z, l;
  } a[N];
  int q[N], h = 1, t = 0, Ans = 0;
  
  Int T[226][305][305] = {0};
  
  bool cmp(Node x, Node y) {
    return (x.x == y.x ? x.y < y.y : x.x < y.x);
  }

  int lb(int x) {
    return x & -x;
  }

  void add(int x, int y, int z, int X) {
    for (int i = x; i <= 3 * m; i += lb(i)) {
      for (int j = y; j <= 3 * m + L; j += lb(j)) {
        for (int k = z; k <= 3 * m + L; k += lb(k)) {
          T[i][j][k] += X;
        }
      }
    }
  }

  int ask(int x, int y, int z) {
    int ans = 0;
    for (int i = min(3 * m, x); i; i -= lb(i)) {
      for (int j = min(3 * m + L, y); j; j -= lb(j)) {
        for (int k = min(3 * m + L, z); k; k -= lb(k)) {
          ans += T[i][j][k];
        }
      }
    }
    return ans;
  }

  void work() {
    For(i,1,n) cin >> a[i].x >> a[i].y >> a[i].z;
    For(i,1,n) {
      int x = (a[i].x - a[i].y - a[i].z), y = (a[i].x + a[i].y + a[i].z), 
          z = (a[i].x + a[i].y - a[i].z) + L, l = (a[i].x - a[i].y + a[i].z) + L;
      a[i].x = x, a[i].y = y, a[i].z = z, a[i].l = l;
    }
    sort(a + 1, a + n + 1, cmp);
    For(i,1,n) {
      while(t - h + 1 > 0 && a[i].x - a[q[h]].x > d) {
        add(a[q[h]].y, a[q[h]].z, a[q[h]].l, -1);
        h++;
      }
      int x1 = a[i].y + d, y1 = a[i].z + d, z1 = a[i].l + d;
      int x2 = max(0ll, a[i].y - d - 1), y2 = max(0ll, a[i].z - d - 1), z2 = max(0ll, a[i].l - d - 1);
      Ans += (ask(x1, y1, z1) - ask(x2, y1, z1) - ask(x1, y2, z1) - ask(x1, y1, z2)
      + ask(x2, y1, z2) + ask(x1, y2, z2) + ask(x2, y2, z1) - ask(x2, y2, z2));
      add(a[i].y, a[i].z, a[i].l, 1);
      q[++t] = i;
    }
    cout << Ans << '\n';
  }
}

signed main() {
  ios::sync_with_stdio(0);
  cin.tie(0), cout.tie(0);
  cin >> B >> n >> d >> m;
  if(B == 1) {
    Solve1::work();
  } else if(B == 2) {
    Solve2::work();
  } else {
    Solve3::work();
  }
  return 0;
}

