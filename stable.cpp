#include<bits/stdc++.h>
#define ALL(v) (v).begin(), (v).end()
#define fi first
#define se second
#define MASK(i) (1LL << (i))
#define BIT(x, i) (((x) >> (i)) & 1)
#define ll long long
#define pii pair<int,int>

using namespace std;

bool minimize(int &x, const int &y){
    if(x > y){
        x = y;
        return true;
    } else return false;
}

bool maximize(int &x, const int &y){
    if(x < y){
        x = y;
        return true;
    } else return false;
}

#define NAME "a"

const int N = (int)1e4 + 5;

int n, m, s;
int dist[N], numWay[N];
vector<int> adj[N], topo;

void init(){
    memset(dist, 0x3f, sizeof dist);
    cin >> n >> m >> s;
    vector<pii> edge;
    while(m--){
        int u, v; cin >> u >> v;
        edge.emplace_back(u, v);
    }
    sort(ALL(edge));
    edge.erase(unique(ALL(edge)), edge.end());
    for(pii x : edge)
        adj[x.fi].emplace_back(x.se);
}

void makeTopo(){
    bool visited[N];
    memset(visited, 0, sizeof visited);
    visited[s] = 1;
    queue<int> q;
    q.emplace(s);
    while(!q.empty()){
        int u =  q.front(); q.pop();
        topo.emplace_back(u);

        for(int v : adj[u]) if(!visited[v]){
            visited[v] = true;
            q.push(v);
        }
    }
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    init();
    makeTopo();
    numWay[s] = 1; dist[s] = 0;
    for(int u : topo) for(int v : adj[u]){
        if(dist[v] == dist[u] + 1) numWay[v] = min(2, numWay[v] + numWay[u]);
        else if(minimize(dist[v], dist[u] + 1)) numWay[v] = numWay[u];
    }
    int res = 0;
    for(int i = 1; i <= n; i++)
        res += (numWay[i] == 2);
    cout << res;
    return 0;
}

