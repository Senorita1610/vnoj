#include <bits/stdc++.h>
//#include <ext/pb_ds/assoc_container.hpp>
//#include <ext/pb_ds/tree_policy.hpp>
 
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("-O3")
#pragma GCC optimize("Ofast")
 
#define N 200051
#define NN 1005000
#define PB push_back
#define M ll(1e9 + 7)
#define all(x) x.begin(), x.end()
#define sz(x) int(x.size())
#define pri(x) cout << x << endl
#define endl '\n'
#define _ << " " <<
#define F first
#define S second
 
using namespace std;
//using namespace __gnu_pbds;
 
typedef long long ll;
//typedef tree <ll, null_type, less_equal <ll>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;
 
typedef long double ld;
typedef unsigned long long ull;
typedef short int si;
 
struct node
{
    int sum = 0;
 
    node *l, *r;
 
    node(): sum(1), l(nullptr), r(nullptr) {}
    node(int sm): sum(sm), l(nullptr), r(nullptr) {}
 
    node(node *lt, node *rt): l(lt), r(rt), sum(lt->sum + rt->sum) {}
};
 
vector <node*> vr;
 
int tt[N * 4];
 
node* bld(int tl, int tr)
{
    if (tl == tr) return new node();
    else
    {
        int md = (tl + tr) >> 1;
 
        return new node(bld(tl, md), bld(md + 1, tr));
    }
}
 
node* upd(node *v, int tl, int tr, int ps)
{
    if (tl == tr)
    {
        return new node(0);
    }
 
    int md = (tl + tr) >> 1;
 
    if (v ->l->sum >= ps)
    {
        return new node(upd(v->l, tl, md, ps), v->r);
    }
    else
    {
        return new node(v->l, upd(v->r, md + 1, tr, ps - v->l->sum));
    }
}
 
int opr(node *v, int tl, int tr, int ps)
{
    if (tl == tr)
        return tl;
 
    int md = (tl + tr) >> 1;
 
    if (v->l->sum >= ps)
        return opr(v->l, tl, md, ps);
 
    return opr(v->r, md + 1, tr, ps - v->l->sum);
}
 
int n, q, t;
ll a[N];
 
ll lft(int i) {return 1ll * i * (i - 1) / 2;}
 
vector <ll> vt;
 
 
void updr(int v, int tl, int tr, int ps, int val)
{
    if (tl == tr)
    {
        tt[v] = val;
 
        return;
    }
 
    int md = (tl + tr) >> 1;
 
    if (ps <= md)
        updr(v + v, tl, md, ps, val);
            else updr(v + v + 1, md + 1, tr, ps, val);
 
    tt[v] = min(tt[v + v], tt[v + v + 1]);
}
 
int get(int v, int tl, int tr, int l, int r)
{
    if (tr < l || r < tl || l > r || tl > tr) return 1e9;
 
    if (l <= tl && tr <= r)
        return tt[v];
 
    int md = (tl + tr) >> 1;
 
    return min(get(v + v, tl, md, l, r), get(v + v + 1, md + 1, tr, l, r));
}
 
 
ll ans(ll x, ll y)
{
    if (x == y)
        return x;
 
    int l = upper_bound(all(vt), x) - 1 - vt.begin();
    int r = upper_bound(all(vt), y) - 1 - vt.begin();
 
    l++; r++;
 
    ll xr = x, yr = y;
 
    x -= lft(l);
 
    y -= lft(r);
 
    x = opr(vr[n + 1 - l], 1, n + 1, x);
 
    y = opr(vr[n + 1 - r], 1, n + 1, y);
 
    if (x > y)
        swap(x, y);
    int lt;
 
    lt = min(l, min(r, get(1, 1, n + 1, x, y - 1)));
 
    if (lt == l)
        return xr;
 
    if (lt == r)
        return yr;
 
    return a[lt];
}
 
int main()
{
    ios_base::sync_with_stdio(0); istream::sync_with_stdio(0); cin.tie(0); cout.tie(0);
 
//    freopen("1.in", "r", stdin);
 
    for (int i = 0; i < N * 4; i++)
        tt[i] = 1e9;
 
    cin >> n >> q >> t;
 
    ll m = (1ll * (n + 1) * (n + 2)) / 2;
 
    vr.PB(bld(1, n + 1));
 
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
 
        vt.PB(lft(i) + 1);
    }
 
    for (int i = n; i >= 1; i--)
    {
        int l = a[i] - lft(i);
 
        int p = opr(vr.back(), 1, n + 1, l);
 
        vr.PB(upd(vr.back(), 1, n + 1, l));
 
        updr(1, 1, n + 1, p, i);
    }
 
    vt.PB(lft(n + 1) + 1);
 
    ll lst = 0;
 
    for (; q > 0; q--)
    {
        ll x, y;
 
        cin >> x >> y;
 
        x = (x - 1 + t * lst) % m + 1;
 
        y = (y - 1 + t * lst) % m + 1;
 
        lst = ans(x, y);
 
        pri(lst);
    }
}

