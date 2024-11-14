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
#define For(i,a,b) for(int i=a;i<=b;i++)
#define Ford(i,a,b) for(int i=a;i>=b;i--)
#define fi first
#define se second
#define ll long long
#define pb push_back
#define sz size()
using namespace std;
typedef pair<int, int> ii;
typedef pair<long long, int> lli;
const int N = 210;
int n,m,ntest,c;
vector<int> ke[N],w[N];
ll d[N],oo;
priority_queue < lli, vector<lli>, greater<lli> > pq;

ll tinh(ll x, int y) {
    if (c<y) return oo;
    if ((c==y)&&(x!=0)) return oo;
    if (x==0) return y;
    if (c>=x+y) return x+y;
    if (c<=2*y) return oo;
    ll k=(x-c+y)/(c-2*y);
    if ((x-c+y)%(c-2*y)) k++;
    return 2*y*k+y+x;
}

void Dij() {
    pq.push(lli(0,n));
    while (pq.size()) {
        int u = pq.top().se;
        pq.pop();
        if (u==1) {
            printf("%lld\n",d[1]);
            return;
        }
        For(j,0,(int)ke[u].sz-1) {
            int v=ke[u][j];
            ll x = tinh(d[u],w[u][j]);
            if (x<d[v]) {
                d[v]=x;
                pq.push(lli(d[v],v));
            }
        }
    }
}

int main() {
    scanf("%d",&ntest);
    oo = 10000000000000000;
    while (ntest) {
        ntest--;
        scanf("%d%d%d",&n,&m,&c);
        For(i,1,n) {ke[i].clear(); w[i].clear(); d[i]=oo; }
        while (!pq.empty()) pq.pop();
        d[n]=0;
        For(i,1,m) {
            int u,v,l;
            scanf("%d%d%d",&u,&v,&l);
            ke[u].pb(v); w[u].pb(l);
            ke[v].pb(u); w[v].pb(l);
        }
        Dij();
    }
}

