#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

const int N = 1000006;
int n;
int num = 0, numi[N];
string query[N];
int val[N];

int BIT[N];
map<int, int> pos;
int nCur;

void update(int u, int v) {
  int idx = u;
  while (idx <= num) {
    BIT[idx] += v;
    idx += (idx & (-idx));
  }
}
int getSum(int p) {
  int idx = p, ans = 0;
  while (idx > 0) {
    ans += BIT[idx];
    idx -= (idx & (-idx));
  }
  return ans;
}

int binSearch(int x) {
  int l = 1, r = num;
  int res = 0;
  while (l <= r) {
    int mid = (l + r) / 2;
    if (getSum(mid) >= x) {
      res = mid;
      r = mid - 1;
    }
    else
      l = mid + 1;
  }
  return res;
}

void solve() {
  if (nCur % 2 != 0)
    cout << numi[binSearch(nCur / 2 + 1)] << "\n";
  else {
    double med_1 = numi[binSearch(nCur / 2)];
    double med_2 = numi[binSearch(nCur / 2 + 1)];
    double res = (med_1 + med_2) / 2;
    cout << res << endl;
  }
}

signed main(void) {
  ios::sync_with_stdio(0); cin.tie(nullptr);
  #ifdef ziwok
  freopen("input.txt","r",stdin);
  freopen("output.txt","w",stdout);
  #endif
  
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> query[i];
    if (query[i] != "MEDIAN")
      cin >> val[i];
    if (query[i] == "IN")
      numi[++num] = val[i];
  }
  sort(numi + 1, numi + num + 1);
  for (int i = 1; i <= num; i++)
    pos[numi[i]] = i;

  for (int i = 1; i <= n; i++) {
    if (query[i] == "IN") {
      update(pos[val[i]], 1);
      nCur++;
    }
    if (query[i] == "OUT") {
      nCur--;
      update(pos[val[i]], -1);
    }
    if (query[i] == "MEDIAN") {
      solve();
    }
  }
  return 0;
}

