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
typedef long long ll;
typedef unsigned long long ull;

#define For(i,a,b) for(int i=a;i<=b;i++)
#define Rep(i,a,b) for(int i=a;i>=b;i--)
#define fi first
#define se second
#define ld long double
#define pb push_back
#define reset(f,x) memset(f,x,sizeof(f))
#define sz(s) int(s.size())
#define N 5010

int n,m,len[45],f[45][N],qx[N],qy[N],lef,righ,d[45][N];
string s[45];
bool fr[45][N];

void push(int i,int j,int x) {
    if (fr[i][j]) {
        fr[i][j] = false;
        qx[++righ] = i; qy[righ] = j;
        d[i][j] = x;
    }
}

void solve() {
    int i = 0, j = 0;
    while (i < len[1] && i < len[2] && s[1][i] == s[2][i]) i++;
    if (i < min(len[1],len[2])) {
        printf("NIE"); return;
    }
    if (len[1] == len[2]) {
        printf("0"); return;
    }
    reset(fr,true);
    if (len[1] < len[2]) push(2,i,0); else push(1,i,0);
    while (lef < righ) {
        int u = qx[++lef], i = qy[lef];
        For(v,3,n+2) {
            int j = i;
            while (j-i < len[v] && j < len[u] && s[u][j] == s[v][j-i]) j++;
            if (j >= len[u] && (j-i) >= len[v]) {
                printf("%d",d[u][i]+1);
                return;
            }
            if (j >= len[u] || (j-i) >= len[v]) {
                if (j < len[u]) push(u,j,d[u][i]+1);
                if (j - i < len[v]) push(v,j-i,d[u][i]+1);
            }
        }
    }
    printf("NIE");
}

int main() {
    scanf("%d",&n);
    For(i,1,n+2) {
        cin >> len[i] >> s[i];
    }
    solve();
}

