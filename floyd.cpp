#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <math.h>
#include <cstdlib>
#include <ctime>
#include <string.h>

const int maxN = 100010;
const int oo = 1000000000;

using namespace std;

int n, m, kk, nheap;
int head[maxN], ke[maxN], next[maxN], ts[maxN], kq[maxN], h[maxN], pos[maxN], d[maxN], truoc[maxN];

void Doc(){
    int x, y, z;
    scanf("%d%d%d", &n, &m, &kk);
    for(int i = 1; i <= m; i++){
        scanf("%d%d%d", &x, &y, &z);
        ke[i] = y;
        next[i] = head[x];
        head[x] = i;
        ts[i] = z;
        ke[i + m] = x;
        next[i + m] = head[y];
        head[y] = i + m;
        ts[i + m] = z;
    }
}

void Doicho(int &x, int &y){
    int tg = x;
    x = y;
    y = tg;
}

void Upheap(int i){
    if ((i == 1) || (d[h[i / 2]] < d[h[i]])) return;
    Doicho(h[i], h[i / 2]);
    Doicho(pos[h[i]], pos[h[i / 2]]);
    Upheap(i / 2);
}

void Downheap(int i){
    int j = 2 * i;
    if (j > nheap) return;
    if (j < nheap && d[h[j]] > d[h[j + 1]]) j++;
    if (d[h[i]] > d[h[j]]){
        Doicho(h[i], h[j]);
        Doicho(pos[h[i]], pos[h[j]]);
        Downheap(j);
    }
}

void Pus(int x){
    nheap++;
    h[nheap] = x;
    pos[x] = nheap;
    Upheap(nheap);
}

int Pop(){
    int tg = h[1];
    h[1] = h[nheap];
    pos[h[1]] = 1;
    nheap--;
    Downheap(1);
    return tg;
}

void Dijkstra(int u){
    int j, v;
    nheap = 0;
    for(int i = 1; i <= n; i++){
        pos[i] = 0;
        truoc[i] = 0;
    }
    for(int i = 1; i <= n; i++) d[i] = oo;
    d[u] = 0;
    Pus(u);
    do{
        if (nheap == 0) break;
        u = Pop();
      //  cout << u << " " << d[u] <<  endl;
        j = head[u];
        while (j != 0){
            v = ke[j];
            if (d[v] > d[u] + ts[j]){
                d[v] = d[u] + ts[j];
                truoc[v] = u;
                if (pos[v] == 0) Pus(v);
                else Upheap(pos[v]);
            }
            j = next[j];
        }
    }
    while (true);
}

void Lam(){
    int x, u, v, len;
    for(int i = 1; i <= kk; i++){
        scanf("%d%d%d", &x, &u, &v);
        //cin >> x >> u >> v;
        Dijkstra(u);
        if (x == 0) printf("%d\n", d[v]);
        else{
            len = 0;
            while (v != u){
                len++;
                kq[len] = v;
                v = truoc[v];
            }
            len++;
            kq[len] = u;
            cout << len << " ";
            for(int i = len; i >= 1; i--) cout << kq[i] << " ";
            printf("\n");
        }
    }
}

void Inkq(){
}


int main()
{
    //freopen("Floyd.inp", "r", stdin);
    //freopen("Floyd.out", "w", stdout);
    Doc();
    Lam();
    Inkq();
    return 0;
}

