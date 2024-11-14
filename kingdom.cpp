#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <math.h>
#include <vector>
#include <string>
#include <cstring>
#include <map>
#include <set>
#include <queue>
#include <stack>

using namespace std;
typedef pair<int, int> ii;
typedef pair<long long, int> lli;
typedef long long ll;

#define For(i,a,b) for(int i=a;i<=b;i++)
#define Rep(i,a,b) for(int i=a;i>=b;i--)
#define fi first
#define se second
#define ld long double
#define pb push_back
#define sz(s) int(s.size())
#define N 110
#define M 10010

int n,m,money[N],cost[N],mm;
vector<int> ke[N];
int dp[N][M],cha[N];

void dfs(int u) {
    int v;
    For(now,0,m)
      if (now+cost[u] <= m)
         dp[u][now] = dp[cha[u]][now+cost[u]] + money[u];
    For(j,0,sz(ke[u])-1) {
        v = ke[u][j];
        if (!cha[v]) {
            cha[v] = u;
            dfs(v);
        }
    }
    For(now,0,m) dp[cha[u]][now] = max(dp[cha[u]][now], dp[u][now]);
}

void solve() {
    cha[1] = 1;
    dfs(1);
    int res = 0;
    For(i,0,m) res = max(res,dp[1][i]);
    cout << res;
}

int main() {
    scanf("%d%d",&n,&m);
    For(i,2,n) scanf("%d",&money[i]);
    For(i,2,n) scanf("%d",&cost[i]);
    For(i,1,n-1) {
        int u,v;
        scanf("%d%d",&u,&v);
        ke[v].push_back(u);
        ke[u].push_back(v);
    }
    solve();
}

