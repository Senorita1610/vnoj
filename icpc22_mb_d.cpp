#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

int f[10];
void init_f() {
  f[0] = 1;
  for (int i = 1; i <= 9; i++)
    f[i] = f[i-1] * i;
}

void greedy(int n) {
  string ans = "";
  int x = 9;
  while (x >= 1) {
    while (n >= f[x]) {
      n -= f[x];
      ans.push_back('0' + x);
    }
    x--;
  }

  sort(ans.begin(), ans.end());
  cout << ans;
}

signed main(void) {
  ios::sync_with_stdio(0); cin.tie(nullptr);
  int n;
  cin >> n;
  if (n == 1)
    return cout << 0, 0;
  init_f();
  greedy(n);
  return 0;
}

