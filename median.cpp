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
#define N 250010
#define K 5010

int n,k,ntest;
int heapA[K],heapB[K],a[N],nheapA,nheapB,pos[N],mul,seed,add;
bool inheapA[N],inheapB[N];
ll res;

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
    nheapA++; heapA[nheapA] = i;
    pos[i]=nheapA;
    upheapA(i);
}

void popA(int i) {
    int j = pos[i];
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
    pos[i]=nheapB;
    upheapB(i);
}

void popB(int i) {
    int j = pos[i];
    swap(heapB[nheapB],heapB[j]); nheapB--;
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
    res=0; nheapA=0; nheapB=0;
    memset(pos,0,sizeof(pos));
    For(i,1,k-1)
	  push(i);
    For(i,k,n) {
        push(i);
        res += a[heapA[1]];
        pop(i-k+1);
    }
    cout << res << endl;
}

int main() {
    scanf("%d",&ntest);
    For(nn,1,ntest) {
        printf("Case #%d: ",nn);
        scanf("%d%d%d%d%d\n",&seed,&mul,&add,&n,&k);
        a[1]=seed;
        For(i,2,n) a[i] = ((ll)a[i-1]*mul+add) % 65536;
        solve();
    }
}

