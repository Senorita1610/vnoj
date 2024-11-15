#include <iostream>
#include <fstream>
#include <sstream>
#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <climits>
#include <vector>
#include <stack>
#include <queue>
#include <set>
#include <map>
 
using namespace std;
 
typedef long long       ll;
typedef double          real;

const int   N = 50000, mod = 1000000000;
int         n, k, a[N], vt[N];
ll          res, f[20][N], t[N];
 
ll get(int x)
{
    ll ans = 0;
    while (x <= n) {
        ans = (ans + t[x]) % mod;
        x += x & (-x);
    }
    return ans;
}
 
void update(int x, ll add)
{
    while (x > 0) {
        t[x] = (t[x] + add) % mod;
        x -= x & (-x);
    }
}
 
int main()
{
    scanf("%d%d", &n,&k);
    for (int i=1;i<=n;i++) {
        scanf("%d", &a[i]);
        vt[a[i]] = i;
    }
 
    for (int i=1;i<=n;i++) f[1][i] = 1;
    for (int i=2;i<=k;i++) {
        for (int j=1;j<=n;j++) t[j] = 0;
        for (int j=1;j<=n;j++) {
            f[i][j] = get(a[j]+1);
            update(a[j], f[i-1][j]);
        }
    }
    for (int i=1;i<=n;i++)
        res = (res + f[k][i]) % mod;
 
    printf("%lld", res);
 
    return 0;
}

