#include<bits/stdc++.h>
#define FOR(i,a,b) for (int i=(a),_b=(b);i<=_b;i=i+1)
#define REP(i,n) for (int i=0,_n=(n);i<_n;i=i+1)
using namespace std;
typedef long long ll;
struct Number {
    int nd,d[30];
    Number() {
        nd=0;
        memset(d,0,sizeof d);
    }
    Number(ll x) {
        nd=0;
        memset(d,0,sizeof d);
        if (x==0) nd++;
        while (x>0) {
            d[nd++]=x%10;
            x/=10;
        }
    }
    int operator [] (int x) const {
        if (x>nd) return (0);
        return (d[nd-1-x]);
    }
};
ll f[20][2][2];
ll Count(ll x) {
    if (x<0) return (0);
    Number tmp(x);
    memset(f,0,sizeof f);
    f[0][0][0]=1;
    REP(i,tmp.nd) REP(j,2) REP(k,2) if (f[i][j][k]>0)
        REP(t,10) if ((!j || t!=3) && (k || t<=tmp[i]))
            f[i+1][t==1][k||t<tmp[i]]+=f[i][j][k];
    ll res=0;
    REP(i,2) REP(j,2) res+=f[tmp.nd][i][j];
    return (res);
}
int main(void) {
    ll a,b;
    ios::sync_with_stdio(false);
    while (cin>>a>>b) cout<<Count(b)-Count(a-1)<<"\n";
    return 0;
}

