#include<bits/stdc++.h>
#pragma GCC optimize ("O3")
#pragma GCC optimize ("unroll-loops")
#pragma GCC target("popcnt")
#define int long long
#define endl "\n"
#define F first
#define S second
#define pb push_back
#define CHECKBIT(mask,i) ((mask>>(i) )&1) // == 1 la bat, == 0 la tat
#define OFFBIT(mask,i) ((1<<(i))^mask) // tat bit thu i
#define ONBIT(mask,i) ((1<<(i))mask) // bat bit thu i
using namespace std;
const long long oo = 1e9+7;
const int N = 2 * 1e5 + 10;
int n, a[505][505],  k;
vector <int> ans;
int t[505][505];
bool dd[505][505];
void inp(){
    cin >> n >> k;
//    assert(k <= 100000);
    for (int i = 1;i <= n;i++){
        for (int j = 1;j <= n;j++){
            cin >> a[i][j];
        }
    }
    return;
}
void case1(int u,int p,int tt){
    int len = tt - t[a[u][p]][a[a[u][p]][u]];
    int du =(k - (t[a[u][p]][a[a[u][p]][u]] ) )% len ;
    cout << ans[(t[a[u][p]][a[a[u][p]][u]]  ) + du - 1ll];
    return;
}
void solve(){
    ans.pb(1);
    ans.pb(2);
    int tt = 2;
    dd[1][2] = true;
    t[1][2] = 1;
    int p = 1;
    int u = 2;
    while (tt <= k){
        int preu = u;
        int prep = p;
        if (dd[a[u][p]][a[a[u][p]][u]]){
            case1(u, p ,tt + 1);
            return;
        }
        t[u][a[u][p]] = tt;
        dd[u][a[u][p]] = 1;
        u = a[u][p];
        p = preu;
        ans.pb(u);
        tt++;
    }
    cout << ans[k - 1];
    return;
}
signed main(){
    ios_base::sync_with_stdio(NULL);
    cin.tie(NULL);
    cout.tie(NULL);
    inp();
    solve();
}

