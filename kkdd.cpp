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

#define For(i,a,b) for(int i=a;i<=b;i++)
#define Ford(i,a,b) for(int i=a;i>=b;i--)
#define fi first
#define se second
#define ll long long
#define ld long double
#define pb push_back
#define sz(s) int(s.size())
#define N 10010
#define K 110
#define inf 1000000000000000LL;

int n,k,a[N],heapA[K],heapB[K],nheapA,nheapB,pos[N];
ll res,sumA,sumB;
ll f[N];
bool inheapA[N], inheapB[N];

void upheapA(int i) {
    int cha,con=pos[i];
    while (1) {
        cha=con/2;
        if ((!cha) || (a[heapA[cha]] >= a[heapA[con]])) return;
        swap(heapA[cha],heapA[con]);
        pos[heapA[cha]] = cha; pos[heapA[con]] = con;
        con=cha;
    }
}

void downheapA(int i) {
    int cha=pos[i],con;
    while (1) {
        con=cha*2;
        if (con<nheapA && a[heapA[con]] < a[heapA[con+1]]) con++;
        if (con>nheapA || a[heapA[cha]] >= a[heapA[con]]) return;
        swap(heapA[cha],heapA[con]);
        pos[heapA[cha]] = cha; pos[heapA[con]] = con;
        cha=con;
    }
}

void pushA(int i) {
    inheapA[i]=true; inheapB[i]=false;
    sumA += a[i];
    nheapA++; heapA[nheapA] = i;
    pos[i]=nheapA;
    upheapA(i);
}

void popA(int i) {
    int j = pos[i];
    sumA -= a[i];
    swap(heapA[nheapA],heapA[j]); nheapA--;
    pos[heapA[j]]=j;
    downheapA(heapA[j]);
    upheapA(heapA[j]);
}

void upheapB(int i) {
    int cha,con=pos[i];
    while (1) {
        cha=con/2;
        if ((!cha) || (a[heapB[cha]] <= a[heapB[con]])) return;
        swap(heapB[cha],heapB[con]);
        pos[heapB[cha]] = cha; pos[heapB[con]] = con;
        con=cha;
    }
}

void downheapB(int i) {
    int cha=pos[i],con;
    while (1) {
        con=cha*2;
        if (con<nheapB && a[heapB[con]] > a[heapB[con+1]]) con++;
        if (con>nheapB || a[heapB[cha]] <= a[heapB[con]]) return;
        swap(heapB[cha],heapB[con]);
        pos[heapB[cha]] = cha; pos[heapB[con]] = con;
        cha=con;
    }
}

void pushB(int i) {
    inheapB[i]=true; inheapA[i]=false;
    nheapB++; heapB[nheapB] = i;
    sumB+=a[i];
    pos[i]=nheapB;
    upheapB(i);
}

void popB(int i) {
    int j = pos[i];
    swap(heapB[nheapB],heapB[j]); nheapB--;
    sumB -= a[i];
    pos[heapB[j]]=j;
    downheapB(heapB[j]);
    upheapB(heapB[j]);
}

void push(int i) {
    int x=a[i];
    if (!nheapA) {
        pushA(i); return;
    }
    if (x>=a[heapA[1]]) pushB(i);
     else pushA(i);
    if (nheapB>nheapA) {
        int j = heapB[1];
        popB(j);
        pushA(j);
    } else if (nheapA-nheapB>1) {
        int j=heapA[1];
        popA(j);
        pushB(j);
    }
}

void pop(int i) {
    if (inheapA[i]) popA(i);
     else popB(i);
    if (nheapB>nheapA) {
        int j = heapB[1];
        popB(j);
        pushA(j);
    } else if (nheapA-nheapB>1) {
        int j=heapA[1];
        popA(j);
        pushB(j);
    }
}

void solve() {
    f[0]=0;
    For(i,1,n) f[i]=inf;
    For(i,k,n) {
        nheapA=0; nheapB=0;
        sumA=0; sumB=0;
        Ford(j,i,i-k+2) push(j);
        Ford(j,i-k+1,max(i-2*k+2,1)) {
            push(j);
            ll x = a[heapA[1]];
            ll X = x*nheapA - sumA + sumB - x*nheapB;
            f[i]=min(f[i],f[j-1]+X);
        }
    }
    cout << f[n];
}

int main() {
    scanf("%d%d",&n,&k);
    For(i,1,n) scanf("%d",&a[i]);
    solve();
}

