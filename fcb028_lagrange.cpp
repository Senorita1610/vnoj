#include <bits/stdc++.h>
using namespace std;

int main() {
  int n; cin >> n;
  if (n == 1) cout << 1 << '\n';
  else if (n == 2) cout << 2 << '\n';
  else if (n <= 6) cout << 3 << '\n';
  else cout << 4 << '\n';
}

