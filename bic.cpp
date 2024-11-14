#include <iostream>
#include <cstdio>
#include <vector>
#include <queue>

using namespace std;

typedef vector<int> VI;
typedef unsigned int uint;

#define maxn 10010
#define pb push_back
#define mod 1000000000

int n;
VI ke[maxn], ken[maxn];
int dist[maxn], f[maxn];
bool inq[maxn], larger[maxn], dt[maxn], vs[maxn];
queue<int> q;

void tinh(int i) {
    if(i==2) {
        f[i] = 1;
        larger[i] = false;
        return;
    }
    if(dt[i]) return;
    dt[i] = true;
    f[i] = 0;
    larger[i] = false;
    for(uint k=0;k<ke[i].size();++k) {
        int j = ke[i][k];
        tinh(j);
        f[i] += f[j];
        larger[i] |= larger[j];
        if(f[i]>=mod) {
            f[i] -= mod;
            larger[i] = true;
        }
    }
}

int main() {
    int u, v, m;
    scanf("%d%d",&n,&m);
    for(int i=0;i<m;++i) {
        scanf("%d%d",&u,&v);
        ke[u].pb(v);
        ken[v].pb(u);
    }

    vs[1] = true;
    q.push(1);
    while(!q.empty()) {
        int u = q.front(); q.pop();
        for(uint k=0;k<ke[u].size();++k) {
            int v = ke[u][k];
            if(!vs[v]) {
                vs[v] = true;
                q.push(v);
            }
        }
    }

    if(!vs[2]) {
        puts("0");
        return 0;
    }

    q.push(2);
    dist[2] = 0;
    inq[2] = true;
    bool vc = false;
    while(!q.empty()) {
        int u = q.front(); q.pop();
        inq[u] = false;
        if(dist[u]>n) {
            vc = true;
            break;
        }
        for(uint k=0;k<ken[u].size();++k) {
            int v = ken[u][k];
            if(dist[v]<dist[u]+1 && vs[v]) {
                dist[v] = dist[u]+1;
                if(!inq[v]) {
                    q.push(v);
                    inq[v] = true;
                }
            }
        }
    }
    if(vc) puts("inf");
    else {
        tinh(1);
        if(larger[1]) printf("%09d",f[1]);
        else printf("%d",f[1]);
    }
    //system("pause");
    return 0;
}

