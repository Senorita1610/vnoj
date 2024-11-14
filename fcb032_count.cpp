#include<bits/stdc++.h>
using namespace std;
const int N=2e5;
int n;
int id[N+5];
vector<vector<int>>adj(N+5);
set<int>s[N+5];
int res[N+5];
void dfs(int u,int par) {
    for (auto v:adj[u]) {
        if (v==par) continue;
        dfs(v,u);
        if (s[id[u]].size()>=s[id[v]].size()) {
            for (auto i:s[id[v]]) s[id[u]].insert(i);
        } else {
            for (auto i:s[id[u]]) s[id[v]].insert(i);
            id[u]=id[v];
        }
    }
    res[u]=s[id[u]].size();
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin>>n;
    for (int i=1;i<n;i++) {
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    for (int i=1;i<=n;i++) {
        int t;
        cin>>t;
        id[i]=i;
        s[i].insert(t);
    }
    dfs(1,0);
    for (int i=1;i<=n;i++) cout<<res[i]<<' ';
}

