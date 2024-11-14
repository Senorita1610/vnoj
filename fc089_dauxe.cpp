#include<bits/stdc++.h>
#define LL long long
#define fi first
#define se second
#define mk make_pair
#define pii pair<int, int>

using namespace std;

const int N = 20007;
const int M = 1e6 + 7;
const int inf = 0x3f3f3f3f;
const LL INF = 0x3f3f3f3f3f3f3f3f;
const int mod = 1e9 +7;

int a[4][N], n, k;
vector<int> ans[3];

pii getPos(int id) {
    if (id < n) return mk(1, id);
    else return mk(2, 2 * n - 1 - id);
}

void add(int x, int y, int z) {
    ans[0].push_back(x);
    ans[1].push_back(y);
    ans[2].push_back(z);
}

int main() {
    scanf("%d%d", &n, &k);

    for(int i = 0; i < 4; i++) {
        for(int j = 0; j < n; j++) {
            scanf("%d", &a[i][j]);
        }
    }

    for(int j = 0; j < n; j++) {
        if(a[0][j] == 0) continue;
        if(a[0][j] == a[1][j]) {
            add(a[0][j], 0, j);
            k--;
            a[1][j] = 0;
        }
    }

    for(int j = 0; j < n; j++) {
        if(a[3][j] == 0) continue;
        if(a[3][j] == a[2][j]) {
            add(a[3][j], 3, j);
            k--;
            a[2][j] = 0;
        }
    }

    if(k == 2 * n) {
        puts("-1");
        return 0;
    }

    while(k > 0) {
        for(int i = 0; i < 2 * n; i++) {
            pii u = getPos(i);
            if(a[u.first][u.second] == 0) continue;
            if(a[u.first ^ 1][u.second] == a[u.first][u.second]) {
                add(a[u.first][u.second], u.first ^ 1, u.second);
                k--;
                a[u.first][u.second] = 0;
                continue;
            }

            pii v = getPos((i + 2 * n - 1) % (2 * n));
            if(a[v.first][v.second] != 0) continue;
            add(a[u.first][u.second], v.first, v.second);
            swap(a[u.first][u.second], a[v.first][v.second]);
        }
    }

    printf("%d\n", ans[0].size());
    for(int i = 0; i < ans[0].size(); i++) {
        printf("%d %d %d\n", ans[0][i], ans[1][i] + 1, ans[2][i] + 1);
    }

    return 0;
}

