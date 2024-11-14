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
#include <stack>

using namespace std;
typedef pair<int, int> ii;
typedef pair<long long, int> lli;
typedef pair<double, int> di;

#define For(i,a,b) for(int i=a;i<=b;i++)
#define Ford(i,a,b) for(int i=a;i>=b;i--)
#define fi first
#define se second
#define ll long long
#define ld long double
#define pb push_back
#define sz(s) int(s.size())
#define eps 0.001
#define oo 8388608
#define N 110

int n,m,top;
vector<int> ke[N],w[N];
double d[N];
int Q[N*N];
int dem[N];
double res;
bool fr[N];

bool check(double x) {
    For(i,1,1) {
        For(u,1,n) d[u]=oo; d[i]=0;
        memset(dem,0,sizeof(dem));
        memset(fr,true,sizeof(fr));
        top=1; Q[1]=i; fr[i]=false;
        while (top) {
            int u,v;
            u=Q[top]; top--;
            fr[u]=true;
            if (dem[u]==n) return true;
            For(j,0,sz(ke[u])-1) {
                v=ke[u][j];
                if (d[v]>d[u]+w[u][j]-x) {
                    d[v]=d[u]+w[u][j]-x;
                    if (fr[v]) {
                        dem[v]++; Q[++top]=v;
                        if (dem[v]==n) return true;
                        fr[v]=false;
                    }
                }
            }
        }
    }
    return false;
}

int main() {
    scanf("%d%d",&n,&m);
    For(i,1,m) {
        int u,v,l;
        scanf("%d%d%d",&u,&v,&l);
        ke[u].pb(v); w[u].pb(l);
    }
    res=oo;
    double d,c,mid;
    d=0; c=oo;
    while (d<=c-eps) {
        mid = (d+c)/2;
        if (check(mid)) { res=mid; c=mid-eps;}
         else d=mid+eps;
    }
    if (res==oo) printf("%d",-1); else printf("%.2lf",res);
}

