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
#define pb push_back
#define sz(s) int(s.size())
#define reset(f,x) memset(f,x,sizeof(f))
#define N 2010
#define inf 1000000001

unsigned int m,n,k,f[N][N][2],dp[26],dd[N][N],kq[N],g[N][N];
char a[N][N],s[N];
vector<int> pos[N][26];
bool check[N][N][2];

void init() {
    Rep(i,m,1) {
        int ch = int(s[i])+1;
        if (ch > int('z')) s[i] = 'a';
        else {
            s[i] = char(ch);
            break;
        }
    }
    For(i,1,m) For(j,1,n) {
        int ch = int(a[i][j]) - int('a');
        pos[i][ch].pb(j);
    }
}

int cal(int i,int j,int tt) {
    if (check[i][j][tt]) return f[i][j][tt];
    if (i == m) {
        f[i][j][tt] = 1;
        check[i][j][tt] = true;
        return 1;
    }
    int res = 0;
    For(k,-1,1) {
        int jj = j + k;
        if (jj > 0 && jj <= n) {
            int t1;
            if (tt == 1 || a[i+1][jj] > s[i+1]) t1 = 1;
            else if (a[i+1][jj] == s[i+1]) t1 = 0;
            else t1 = -1;
            if (t1 >= 0) {
                res += cal(i+1,jj,t1);
                if (res > inf) res = inf;
            }
        }
    }
    f[i][j][tt] = res;
    check[i][j][tt] = true;
    return res;
}

void solve() {
    init();
    For(j,1,n) cal(0,j,0);
    For(j,1,n) {
        int ch = int(a[1][j]) - 97;
        if (a[1][j] > s[1]) dp[ch] = dp[ch] + f[1][j][1];
        else dp[ch] += f[1][j][0];
        if (dp[ch] > inf) dp[ch] = inf;
    }
    bool bigger = false;
    For(ch,0,25) if (dp[ch] < k) k -= dp[ch];
    else {
        if (ch > int(s[1]) - 97) bigger = true;
        For(j,0,sz(pos[1][ch])-1) {
            dd[1][pos[1][ch][j]] = 1;
            g[1][pos[1][ch][j]] = 1;
        }
        kq[1] = ch;
        break;
    }
    For(i,2,m) {
        For(ch,0,25) dp[ch] = 0;
        For(j,1,n) {
            int ch = int(a[i][j]) - 97;
            g[i][j] = g[i-1][j-1] + g[i-1][j] + g[i-1][j+1];
            if (g[i][j] > inf) g[i][j] = inf;
            ull temp;
            if (bigger || a[i][j] > s[i]) temp = ull(g[i][j]) * f[i][j][1];
            else if (a[i][j] == s[i]) temp = ull(g[i][j]) * f[i][j][0];
            if (temp > inf) temp = inf;
            dp[ch] += temp;
            if (dp[ch] > inf) dp[ch] = inf;
        }
        int bound;
        if (bigger) bound = 0;
        else bound = int(s[i])-97;
        For(ch,bound,25) if (dp[ch] < k) k -= dp[ch];
        else {
            if (ch > int(s[i])-97) bigger = true;
            kq[i] = ch;
            For(j,1,n) g[i][j] = 0;
            For(j,0,sz(pos[i][ch])-1) {
                int v = pos[i][ch][j];
                unsigned int x = g[i-1][v-1] + g[i-1][v] + g[i-1][v+1];
                if (x > inf) x = inf;
                g[i][v] = x;
            }
            break;
        }
    }
    For(i,1,m) cout << char(kq[i]+97);
}

int main() {
    scanf("%d%d%d",&m,&n,&k);
    scanf("%s",(s+1));
    For(i,1,m) scanf("%s",(a[i]+1));
    solve();
}

