#include <map>
#include <set>
#include <list>
#include <cmath>
#include <queue>
#include <stack>
#include <bitset>
#include <vector>
#include <cstdio>
#include <string>
#include <sstream>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
#define PB push_back
#define MP make_pair
#define SZ(v) ((int)(v).size())
#define abs(x) ((x) > 0 ? (x) : -(x))
typedef long long LL;

#define MAXN 100005
#define fi first
#define se second
const int dx[8] = {0, 1, 1, 1, 0, -1, -1, -1};
const int dy[8] = {1, 1, 0, -1, -1, -1, 0, 1};
int xm, ym, xb, yb;
int n;
double ret;
char turn[MAXN];
pair<int, int> f[MAXN][8];

void update(int x, int y) {
    ret = min(ret, (double)(xb - x) * (xb - x) + (double)(yb - y) * (yb - y));
}

int main() {
    scanf("%d%d%d%d%d", &xm, &ym, &xb, &yb, &n);
    scanf("%s", turn + 1);
    for (int i = n; i; i--)
        for (int j = 0; j < 8; j++) {
            int k = (j - (turn[i] - '0') + 8) % 8;
            f[i][j].fi = f[i + 1][k].fi + dx[k];
            f[i][j].se = f[i + 1][k].se + dy[k];
        }
    int x = 0, y = 0, d = 0;
    ret = 1e20;
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j < 8; j++) {
            int dd = (d + j) % 8;
            update(xm + x + dx[dd] + f[i + 1][dd].fi, ym + y + dy[dd] + f[i + 1][dd].se);
        }
        d = (d - (turn[i] - '0') + 8) % 8;
        x += dx[d]; y += dy[d];
    }
    printf("%.6f\n", sqrt(ret));
    return 0;
}

