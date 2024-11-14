#include <algorithm>
#include <cstdio>
#include <cstring>
#include <set>
#include <queue>

const int MaxN = 300000;

typedef struct vec_t {
  long long x, y;
  vec_t(long long _x = 0, long long _y = 0) { x = _x, y = _y; }
  inline friend bool operator<(const vec_t &a, const vec_t &b) { return a.x < b.x; }
  inline friend vec_t operator-(const vec_t &a, const vec_t &b) { return vec_t(a.x - b.x, a.y - b.y); }
  inline friend long long cross(const vec_t &a, const vec_t &b) { return a.x * b.y - a.y * b.x; }
} node_t;

int N;
long long Area;
node_t A[MaxN + 5];
bool Del[MaxN + 5];
int Id[MaxN + 5];
long long Ans[MaxN + 5];
std::priority_queue< std::pair<int, int> > _L, _R, _U, _D;
std::set<int> Up, Down;

void init() {
  scanf("%d", &N);
  for (int i = 1; i <= N; ++i) scanf("%lld %lld", &A[i].x, &A[i].y);
  std::sort(A + 1, A + 1 + N);
  for (int i = 1; i <= N; ++i) {
    _L.push(std::make_pair(-A[i].x, i));
    _R.push(std::make_pair(A[i].x, i));
    _U.push(std::make_pair(A[i].y, i));
    _D.push(std::make_pair(-A[i].y, i));
  }
  static char s[MaxN + 5];
  scanf("%s", s + 1);
  for (int i = 1; i <= N - 2; ++i) {
    if (s[i] == 'L') {
      while (Del[_L.top().second] == true) _L.pop();
      Id[i] = _L.top().second;
      Del[_L.top().second] = true;
    } else if (s[i] == 'R') {
      while (Del[_R.top().second] == true) _R.pop();
      Id[i] = _R.top().second;
      Del[_R.top().second] = true;
    } else if (s[i] == 'U') {
      while (Del[_U.top().second] == true) _U.pop();
      Id[i] = _U.top().second;
      Del[_U.top().second] = true;
    } else {
      while (Del[_D.top().second] == true) _D.pop();
      Id[i] = _D.top().second;
      Del[_D.top().second] = true;
    }
  }
}

inline void uppre(int x, std::set<int>::iterator pre) {
  std::set<int>::iterator ppre = pre;
  while (ppre != Up.begin()) {
    ppre--;
    if (cross(A[*pre] - A[x], A[*ppre] - A[*pre]) > 0) break;
    Area -= cross(A[*pre], A[*ppre]);
    Up.erase(pre);
    pre = ppre;
  }
}

inline void upnxt(int x, std::set<int>::iterator nxt) {
  std::set<int>::iterator nnxt = nxt;
  nnxt++;
  while (nnxt != Up.end()) {
    if (cross(A[*nxt] - A[*nnxt], A[x] - A[*nxt]) > 0) break;
    Area -= cross(A[*nnxt], A[*nxt]);
    Up.erase(nxt);
    nxt = nnxt;
    nnxt++;
  }
}

void insertUp(int x) {
  std::set<int>::iterator nxt = Up.lower_bound(x), pre = nxt;
  if (nxt == Up.begin()) {
    upnxt(x, nxt);
    Area += cross(A[*Up.begin()], A[x]);
    Up.insert(x);
  } else if (nxt == Up.end()) {
    pre--;
    uppre(x, pre);
    Area += cross(A[x], A[*(--Up.end())]);
    Up.insert(x);
  } else {
    pre--;
    if (cross(A[x] - A[*nxt], A[*pre] - A[x]) < 0) return;
    Area -= cross(A[*nxt], A[*pre]);
    uppre(x, pre), upnxt(x, nxt);
    nxt = Up.lower_bound(x), pre = nxt;
    pre--;
    Area += cross(A[*nxt], A[x]) + cross(A[x], A[*pre]);
    Up.insert(x);
  }
}

inline void downpre(int x, std::set<int>::iterator pre) {
  std::set<int>::iterator ppre = pre;
  while (ppre != Down.begin()) {
    ppre--;
    if (cross(A[*pre] - A[*ppre], A[x] - A[*pre]) > 0) break;
    Area -= cross(A[*ppre], A[*pre]);
    Down.erase(pre);
    pre = ppre;
  }
}

inline void downnxt(int x, std::set<int>::iterator nxt) {
  std::set<int>::iterator nnxt = nxt;
  nnxt++;
  while (nnxt != Down.end()) {
    if (cross(A[*nxt] - A[x], A[*nnxt] - A[*nxt]) > 0) break;
    Area -= cross(A[*nxt], A[*nnxt]);
    Down.erase(nxt);
    nxt = nnxt;
    nnxt++;
  }
}

void insertDown(int x) {
  std::set<int>::iterator nxt = Down.lower_bound(x), pre = nxt;
  if (nxt == Down.begin()) {
    downnxt(x, nxt);
    Area += cross(A[x], A[*Down.begin()]);
    Down.insert(x);
  } else if (nxt == Down.end()) {
    pre--;
    downpre(x, pre);
    Area += cross(A[*(--Down.end())], A[x]);
    Down.insert(x);
  } else {
    pre--;
    if (cross(A[x] - A[*pre], A[*nxt] - A[x]) < 0) return;
    Area -= cross(A[*pre], A[*nxt]);
    downpre(x, pre), downnxt(x, nxt);
    nxt = Down.lower_bound(x), pre = nxt;
    pre--;
    Area += cross(A[*pre], A[x]) + cross(A[x], A[*nxt]);
    Down.insert(x);
  }
}

void solve() {
  for (int i = 1; i <= N; ++i)
    if (Del[i] == false) {
      Up.insert(i);
      Down.insert(i);
    }
  for (int q = N - 2; q >= 1; --q) {
    int x = Id[q];
    insertUp(x);
    insertDown(x);
    Ans[q] = Area;
  }
  for (int i = 1; i <= N - 2; ++i)
    printf("%lld.%lld\n", Ans[i] >> 1, (Ans[i] & 1) * 5);
}

int main() {
  init();
  solve();
  return 0;
}

