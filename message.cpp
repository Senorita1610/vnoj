#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for (auto i = a; i <= b; i++)
#define repr(i, a, b) for (auto i = a; i >= b; i--)
#define ll long long

const int dx[4] = {-1, 0, 1, 0};
const int dy[4] = {0, 1, 0, -1};

const int NMAX = 8e2 + 3;
int n, m, cnt, connectedComponent = 0;
vector<int> ds[NMAX];
stack<int> st;
int low[NMAX], num[NMAX], inScc[NMAX];
bool inSt[NMAX];
void openf() {
    int u, v;
    cin >> n >> m;
    rep(edge, 1, m) {
        cin >> u >> v;
        ds[u].push_back(v);
    }
}
void tarjan(int u) {
    st.push(u);
    inSt[u] = 1;
    low[u] = num[u] = ++cnt;
    for (auto v: ds[u]) {
        if (num[v] == -1) {
            tarjan(v);
            low[u] = min(low[u], low[v]);
        } else if (inSt[v])
            low[u] = min(low[u], num[v]);
    }

    if (low[u] == num[u]) {
        connectedComponent++;
        while (true) {
            auto curr = st.top();
            inSt[curr] = 0;
            inScc[curr] = connectedComponent;
            st.pop();
            if (curr == u) break;
        }
    }
}
void process() {
    memset(low, -1, sizeof(low));
    memset(num, -1, sizeof(num));
    cnt = 0;
    rep(u, 1, n) 
        if (num[u] == -1) 
            tarjan(u);

    memset(inSt, 0, sizeof(inSt));
    rep(u, 1, n) 
        for (auto v: ds[u])
            if (inScc[u] != inScc[v])
                inSt[inScc[v]] = 1;

    int res = 0;
    rep(u, 1, connectedComponent)
        res += (1 - inSt[u]);

    cout << res;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    openf();
    process();
}

