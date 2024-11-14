#include <bits/stdc++.h>
 
using namespace std;
 
const int maxn = 2e5 + 5;
 
int n;
int a[maxn], b[maxn], f[maxn], g[maxn];
long long ans;
bool DEBUG;
 
inline void calc1(int l, int r, int ql, int qr){
  if(l > r)
    return;
  int md = l + r >> 1, pos = -1;
  long long ret = 0;
  for(int i = ql; i <= qr; ++i){
    long long res = 1ll * (i - md + 1) * min(f[md], f[i]) * min(g[md], g[i]);
    if(!~pos || res >= ret)
      ret = res, pos = i;
  }
  ans = max(ans, ret);
  calc1(l, md - 1, ql, pos);
  calc1(md + 1, r, pos, qr);
  return;
}
 
inline void calc2(int l, int r, int ql, int qr){
  if(l > r)
    return;
  int md = l + r >> 1, pos = -1;
  long long ret = 0;
  for(int i = ql; i <= qr; ++i){
    long long res = 1ll * (i - md + 1) * min(f[md], f[i]) * min(g[md], g[i]);
    if(!~pos || res >= ret)
      ret = res, pos = i;
  }
  ans = max(ans, ret);
  calc2(l, md - 1, pos, qr);
  calc2(md + 1, r, ql, pos);
  return;
}
 
inline void solve(int l, int r){
  if(l == r){
    ans = max(ans, 1ll * a[l] * b[l]);
    return;
  }
  int md = l + r >> 1;
  for(int i = md; i >= l; --i){
    f[i] = min(i == md ? 0x3f3f3f3f : f[i + 1], a[i]);
    g[i] = min(i == md ? 0x3f3f3f3f : g[i + 1], b[i]);
  }
  for(int i = md + 1; i <= r; ++i){
    f[i] = min(i == md + 1 ? 0x3f3f3f3f : f[i - 1], a[i]);
    g[i] = min(i == md + 1 ? 0x3f3f3f3f : g[i - 1], b[i]);
  }
  calc1(l, md, md + 1, r);
  calc2(l, md, md + 1, r);
  solve(l, md), solve(md + 1, r);
  return;
}
 
int main(){
  scanf("%d", &n);
  for(int i = 0; i < n; ++i)
    scanf("%d%d", a + i, b + i);
 
  solve(0, n - 1);
 
  printf("%lld\n", ans);
  return 0;
}

