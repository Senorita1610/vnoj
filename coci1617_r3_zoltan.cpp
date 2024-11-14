#include <bits/stdc++.h>
 
using namespace std;
 
const int md = 1e9 + 7;
 
int add(int a, int b) {
  return a + b < md ? a + b : a + b - md;
}
 
void ckadd(int& a, int b) {
  a = add(a, b);
}
 
int mul(int a, int b) {
  return a * 1LL * b % md;
}
 
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  vector<int> xs = a;
  xs.push_back(-1);
  xs.push_back(1.0001e9);
  sort(xs.begin(), xs.end());
  xs.erase(unique(xs.begin(), xs.end()), xs.end());
  for (int i = 0; i < n; i++) {
    a[i] = (int) (lower_bound(xs.begin(), xs.end(), a[i]) - xs.begin());
  }
  int k = (int) xs.size();
  vector<pair<int, int>> fenw(k, {-1, 0});
  auto Modify = [&](int p, pair<int, int> v) {
    while (p < k) {
      if (fenw[p].first == v.first) {
        ckadd(fenw[p].second, v.second);
      } else {
        fenw[p] = max(fenw[p], v);
      }
      p |= (p + 1);
    }
  };
  auto Query = [&](int p) {
    pair<int, int> ret = {-1, 0};
    while (p >= 0) {
      if (fenw[p].first == ret.first) {
        ckadd(ret.second, fenw[p].second);
      } else {
        ret = max(ret, fenw[p]);
      }
      p = (p & (p + 1)) - 1;
    }
    return ret;
  };
  Modify(0, {0, 1});
  vector<pair<int, int>> dp_big(n);
  vector<pair<int, int>> dp_small(n);
  for (int i = n - 1; i >= 0; i--) {
    dp_big[i] = Query(k - a[i] - 2);
    Modify(k - a[i] - 1, {dp_big[i].first + 1, dp_big[i].second});
  }
  for (int i = 0; i < k; i++){
    fenw[i] = {-1, 0};
  }
  Modify(0, {0, 1});
  for (int i = n - 1; i >= 0; i--) {
    dp_small[i] = Query(a[i] - 1);
    Modify(a[i], {dp_small[i].first + 1, dp_small[i].second});
  }
  pair<int, int> res = {0, 1};
  for (int i = 0; i < n; i++) {
    pair<int, int> my;
    my.first = dp_small[i].first + dp_big[i].first + 1;
    my.second = mul(dp_small[i].second, dp_big[i].second);
    if (my.first == res.first) {
      ckadd(res.second, my.second);
    } else {
      res = max(res, my);
    }
  }
  for (int i = 0; i < n - res.first; i++) {
    res.second = mul(res.second, 2);
  }
  cout << res.first << " " << res.second << '\n';
  return 0;
}

