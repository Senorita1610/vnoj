#include <bits/stdc++.h>
 
using namespace std;
 
#define ll long long
 
const int nx=2e5+5, mod=1e9+2022;
 
int n, m, sz[nx], v[nx];
ll dn[nx], dp[nx];
vector<int> d[nx];
 
ll dfs(int u)
{
    dn[u]=max(1, (int)d[u].size());
    for (auto v:d[u]) dn[u]=(dn[u]*dfs(v))%mod;
    //cout<<"dn"<<' '<<u<<' '<<dn[u]<<'\n';
    return dn[u];
}
 
void dfs2(int u)
{
    vector<ll> pref(d[u].size()+2, 1), suf(d[u].size()+2, 1);
    for (int i=1; i<=d[u].size(); i++) pref[i]=(pref[i-1]*dn[d[u][i-1]])%mod;
    for (int i=d[u].size(); i>=1; i--) suf[i]=(suf[i+1]*dn[d[u][i-1]])%mod;
    for (int i=1; i<=d[u].size(); i++) dp[d[u][i-1]]=((dp[u]*pref[i-1])%mod*suf[i+1])%mod, dfs2(d[u][i-1]);
    //cout<<u<<' '<<dp[u]<<'\n';
}
 
struct segtree
{
    int d1[2*nx], d2[2*nx];
    bool lz[2*nx];
    void build(int l, int r, int i, vector<int> &t)
    {
        if (l==r) return t[l]?d1[i]=v[l]:d2[i]=v[l], void();
        int md=(l+r)/2;
        build(l, md, 2*i, t);
        build(md+1, r, 2*i+1, t);
        d1[i]=(d1[2*i]+d1[2*i+1])%mod;
        d2[i]=(d2[2*i]+d2[2*i+1])%mod;
    }
    void pushlz(int l, int r, int i)
    {
        if (!lz[i]) return;
        lz[i]=0; swap(d1[i], d2[i]);
        if (l==r) return;
        lz[2*i]=!lz[2*i];
        lz[2*i+1]=!lz[2*i+1];
    }
    void update(int l, int r, int i, int ql, int qr)
    {
        pushlz(l, r, i);
        if (r<ql||qr<l) return;
        if (ql<=l&&r<=qr) return lz[i]=1, pushlz(l, r, i), void();
        int md=(l+r)/2;
        update(l, md, 2*i, ql, qr);
        update(md+1, r, 2*i+1, ql, qr);
        d1[i]=(d1[2*i]+d1[2*i+1])%mod;
        d2[i]=(d2[2*i]+d2[2*i+1])%mod;
    }
} s;
 
void init(int N, int M, std::vector<int> P, std::vector<int> A) {
    n=N; m=M;
    for (int i=1; i<N+M; i++) d[P[i]].push_back(i);
    dp[0]=1;
    dfs(0); dfs2(0);
    for (int i=N; i<N+M; i++) v[i-N]=dp[i];
    s.build(0, M-1, 1, A);
}
 
int count_ways(int L, int R) {;
    s.update(0, m-1, 1, L-n, R-n);
    return s.d1[1];
}

