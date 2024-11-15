#include <bits/stdc++.h>
using namespace std;
#define nothing ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define endl "\n"
#define ll long long
#define ull unsigned long long
#define fi first
#define se second
#define pb push_back
const ll oo = 1e13;
const ll modd = 1e9 + 7;
const int maxn = 1e6 + 5;
const int maxa = 2e3 + 5;
const int base = 31;
ll parent[maxn + 2], altitude[maxn + 2];
void make_set(int v) {
    parent[v] = v;
    altitude[v] = 0; 
}
int find_set(int v) {
    if (v == parent[v]) return v; 
    int p = find_set(parent[v]); 
    parent[v] = p; 
    return p;
}
void union_sets(int a, int b) {
    a = find_set(a);
    b = find_set(b);
    if (a != b) {
        if (altitude[a] < altitude[b]) swap(a, b); 
        parent[b] = a;
        if (altitude[a] == altitude[b]) altitude[a]++; 
    } 
}
ll n, m;
int main() {
    nothing
    cin >> n >> m;
    ll ans = m;
    for (int i = 1; i <= n; ++i) make_set(i);
    for (int j = 1; j <= m; ++j) {
    	ll u, v;
        cin >> u >> v;
        int x = find_set(u), y = find_set(v);
        if (x != y) {
        	union_sets(x, y); 
        	ans--;
        }
    }
    cout << ans;
    return 0;
}

