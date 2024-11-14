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

#define For(i,a,b) for(int i=a;i<=b;i++)
#define Ford(i,a,b) for(int i=a;i>=b;i--)
#define fi first
#define se second
#define ll long long
#define ld long double
#define pb push_back
#define sz(s) int(s.size())
#define N 1000010

int n,m,k,s,lab[N],a[N];
vector<int> ke[N],kq;

void dfs(int u) {
    int v;
    lab[u]=1;
    For(j,0,sz(ke[u])-1) {
        v=ke[u][j];
        if (lab[v]==0) dfs(v);
    }
}

void loang(int u) {
    int v;
    lab[u]=1;
    kq.pb(u);
    For(j,0,sz(ke[u])-1) {
        v=ke[u][j];
        if (lab[v]==0) {loang(v); kq.pb(u); }
    }
}

void solve() {
    dfs(s);
    For(i,1,k)
     if (lab[a[k]]==0) { printf("NIE"); return; };
    printf("TAK\n");
    memset(lab,0,sizeof(lab));
    loang(s);
    printf("%d ",sz(kq));
    For(i,0,sz(kq)-1) printf("%d ",kq[i]);
}

int main() {
    scanf("%d%d%d%d",&n,&m,&s,&k);
    For(i,1,m) {
        int u,v;
        scanf("%d%d",&u,&v);
        ke[u].pb(v); ke[v].pb(u);
    }
    For(i,1,k) scanf("%d",&a[i]);
    solve();
}

