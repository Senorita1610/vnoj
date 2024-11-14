#include <variant>
#include <iostream>
#include <vector>
#include <algorithm>
#include <cassert>
using namespace std;
using pii = pair<int, int>;
#define forn(i, n) for(int i=0; i<(int)n; ++i)
#define forsn(i, s, n) for(int i=s; i<(int)n; ++i)
#define dforn(i, n) for(int i=(int)n-1; i>=0; --i)
#define dforsn(i, s, n) for(int i=(int)n-1; i>=s; --i)
#define PB push_back
#define F first
#define S second
 
const int MAXN = 100010;
int n, m, uv, ue, cur, stpos[MAXN];
bool vis[MAXN], blocked[MAXN], inst[MAXN];
vector<int> st, se, stt, see, t1, t2, c1, c2, v1, v2, ans;
vector<pii> g[MAXN];
 
void build(vector<int>& stv, vector<int>& ste, int v, int e, vector<int>& c, vector<int>& t, vector<int>& a, int th){
  int pos=0;
  while(stv[pos]!=v) ++pos;
  forsn(i, th, pos) t.PB(ste[i]);
  forsn(i, pos, ste.size()) c.PB(ste[i]), a.PB(stv[i]);
  c.PB(e);
  a.PB(stv.back());
}
 
bool dfs2(int v){
  inst[v]=true;
  vis[v]=true;
  stt.PB(v);
  for(pii to:g[v]) if(!vis[to.F] && !blocked[to.F]) {
    see.PB(to.S);
    bool ret = dfs2(to.F);
    if(ret) return true;
  }
  else if((inst[to.F] || stpos[to.F]!=-1) && !blocked[to.F] && to.S != se[cur]){
    int loops;
    build(st, se, uv, ue, c1, t1, v1, cur);
    if(inst[to.F]){
      loops=2;
      build(stt, see, to.F, to.S, c2, t2, v2, 0);
    }
    else{
      loops=1;
      for(int el:see) t2.PB(el);
      t2.PB(to.S);
      int cp = stpos[to.F];
      while(cp<stpos[uv]) t2.PB(se[cp]), ++cp;
      int pos=0;
      while(v1[pos]!=st[cp]) ++pos;
      dforn(i, pos) c2.PB(c1[i]);
      dforsn(i, pos, c1.size()) c2.PB(c1[i]);
    }
 
    forn(i, cur) ans.PB(se[i]);
    forn(lo, loops){
      for(int el:t1) ans.PB(el);
      for(int el:c1) ans.PB(el);
      dforn(i, t1.size()) ans.PB(t1[i]);
      for(int el:t2) ans.PB(el);
      for(int el:c2) ans.PB(el);
      dforn(i, t2.size()) ans.PB(t2[i]);
      reverse(c1.begin(), c1.end());
      reverse(c2.begin(), c2.end());
    }
    dforn(i, cur) ans.PB(se[i]);
    return true;
  }
  inst[v]=false;
  stt.pop_back();
  if(!see.empty()) see.pop_back();
  return false;
}
 
int dfs1(int v){
  stpos[v]=(int)st.size();
  st.PB(v);
  vis[v]=true;
  for(pii to:g[v]) if(!vis[to.F] && !blocked[to.F]){
    se.PB(to.S);
    int ret = dfs1(to.F);
    if(ret) return ret;
  }
  else if(stpos[to.F]!=-1){
    uv = to.F, ue = to.S;
    while(cur<=stpos[to.F]){
      bool ret = dfs2(st[cur]);
      if(ret) return 1;
      blocked[st[cur]]=true;
      ++cur;
    }
  }
  if((int)st.size() <= cur+1) return 2;
  st.pop_back();
  se.pop_back();
  stpos[v]=-1;
  return 0;
}
 
variant<bool, vector<int>> find_journey(int N, int M, vector<int> U, vector<int> V) {
  n=N, m=M;
  forn(i, n) stpos[i]=-1;
  forn(i, m) g[U[i]].PB({V[i], i});
 
  int ret = dfs1(0);
  if(ret==1) return ans;
  else return false;
}

