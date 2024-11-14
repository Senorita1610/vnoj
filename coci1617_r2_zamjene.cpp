#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;
 
 
 
const int N = 1e6 + 5;
 
 
 
int n, m, a[N], b[N];
 
int p[N], sz[N];
long long ha[N], hb[N], P[N], ans;
gp_hash_table < long long, int > q;
 
int dsu_get(int v){
    return p[v] == v ? v : p[v] = dsu_get(p[v]);
}
 
inline void upd(int val, long long hsh, int sz){
    if(hsh != 0){
        ans += 1LL * val * sz * q[-hsh];
    }
    q[hsh] += val * sz;
}
 
inline void dsu_unite(int x, int y){
    x = dsu_get(x);
    y = dsu_get(y);
    if(x == y){
        return;
    }
    upd(-1, hb[x] - ha[x], sz[x]);
    upd(-1, hb[y] - ha[y], sz[y]);
    p[y] = x;
    ha[x] += ha[y];
    hb[x] += hb[y];
    sz[x] += sz[y];
    upd(+1, hb[x] - ha[x], sz[x]);
}
 
inline void dsu_upd(int val, int x, int y, int z){
    ha[x] += val * P[z];
    sz[x] += val;
}
 
main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    P[0] = 1;
    for(int i = 1; i < N; i++){
        P[i] = P[i - 1] * 1234577;
    }
    cin >> n >> m;
    for(int i = 1; i <= n; i++){
        cin >> a[i];
        b[i] = a[i];
        p[i] = i;
        sz[i] = 1;
    }
    sort(b + 1, b + n + 1);
    for(int i = 1; i <= n; i++){
        hb[i] = P[b[i]];
        ha[i] = P[a[i]];
        upd(+1, hb[i] - ha[i], +1);
    }
    while(m--){
        int type;
        cin >> type;
        if(type == 1){
            int x, y;
            cin >> x >> y;
            int px = dsu_get(x),
                py = dsu_get(y);
            if(px == py){
                swap(a[x], a[y]);
                continue;
            }
            upd(-1, hb[px] - ha[px], sz[px]);
            upd(-1, hb[py] - ha[py], sz[py]);
            dsu_upd(-1, dsu_get(x), x, a[x]);
            dsu_upd(-1, dsu_get(y), y, a[y]);
            swap(a[x], a[y]);
            dsu_upd(+1, dsu_get(y), y, a[y]);
            dsu_upd(+1, dsu_get(x), x, a[x]);
            upd(+1, hb[py] - ha[py], sz[py]);
            upd(+1, hb[px] - ha[px], sz[px]);
        }
        else if(type == 2){
            int x, y;
            cin >> x >> y;
            dsu_unite(x, y);
        }
        else if(type == 3){
            cout << (q[0] == n ? "DA\n" : "NE\n");
        }
        else{
            cout << ans << "\n";
        }
    }
}

