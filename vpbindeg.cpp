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

#define For(i,a,b) for(int i=a;i<=b;i++)
#define Rep(i,a,b) for(int i=a;i>=b;i--)
#define fi first
#define se second
#define ld long double
#define pb push_back
#define sz(s) int(s.size())
#define N 100010

int n,f[N],ntest,k,pos[2],next[N][2],back[N][2];
char s[N];
ll res;

void solve() {
    For(i,0,n+1) {
        back[i][0] = 0; back[i][1] = 0;
    }
    pos[0] = n+1; pos[1] = n+1;
    next[n+1][0] = n+1; next[n+1][1] = n+1;
    Rep(i,n,0) {
        next[i][0] = pos[0]; next[i][1] = pos[1];
        if (i) pos[int(s[i]) - int('0')] = i;
    }
    int i = 0;
    For(j,1,k) i = next[i][0];
    if (i > n) { printf("0\n"); return; }
    back[i][0] = next[0][0];
    int j = next[0][0];
    while (i < n) {
        i++;
        if (s[i] == '0') {
            j = next[j][0];
            back[i][0] = j;
        } else back[i][0] = back[i-1][0];
    }
    i = 0;
    For(j,1,k) i = next[i][1];
    if (i > n) { printf("0\n"); return; }
    j = next[0][1];
    back[i][1] = j;
    while (i < n) {
        i++;
        if (s[i] == '1') {
            j = next[j][1];
            back[i][1] = j;
        } else back[i][1] = back[i-1][1];
    }
    For(i,1,n) {
        f[i] = f[i-1];
        if (s[i] == '0') f[i]++;
    }
    res = 0;
    int last = 1;
    For(i,1,n) if (s[i] == '1') {
        int j = back[i][1];
        if (j > 0) {
            j = back[j][0];
            if (j > 0) {
                res += f[j] - f[last-1];
                last = j;
            }
        }
    }
    printf("%lld\n",res);
}

int main() {
    scanf("%d",&ntest);
    while (ntest) {
        ntest--;
        scanf("%d%d",&n,&k);
        scanf("%s",(s+1));
        solve();
    }
}

