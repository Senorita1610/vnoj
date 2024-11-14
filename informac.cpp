#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> ii;
typedef pair<long long, int> lli;
typedef long long ll;
typedef unsigned long long ull;

#define For(i,a,b) for(int i=a;i<=b;i++)
#define Ford(i,a,b) for(int i=a;i>=b;i--)
#define fi first
#define se second
#define pb push_back
#define sz(s) int(s.size())
#define reset(f, x) memset(f, x, sizeof(f))
#define N 210

int n, xmin[N], xmax[N], m, a[N][N], mx[N], my[N], trace[N];
int mi[N], ma[N];
queue<int> q;

int FindPath() {
    while (!q.empty()) q.pop();
    For(i, 1, n) if (!mx[i]) q.push(i);
    reset(trace, 0);
    while (!q.empty()) {
        int i = q.front(); q.pop();
        For(j, 1, n) if (a[i][j] && !trace[j]) {
            trace[j] = i;
            if (!my[j]) return j;
            q.push(my[j]);
        }
    }
    return 0;
}

void IncFlow(int f) {
    while (f) {
        int x = trace[f];
        int next = mx[x];
        mx[x] = f; my[f] = x;
        f = next;
    }
}

void solve() {
    For(i, 1, n) For(j, xmin[i], xmax[i])
    if (i >= mi[j] && i <= ma[j]) a[i][j] = 1;
    For(i, 1, n) For(j, 1, n) if (a[i][j] && !my[j]) {
        my[j] = i; mx[i] = j;
        break;
    }
    int f;
    while ( f = FindPath() )
	IncFlow(f);
    For(i, 1, n) if (!my[i]) {
        cout << -1; return;
    }
    For(i, 1, n) printf("%d ", my[i]);
}

int main() {
    scanf("%d %d", &n, &m);
    For(i, 1, n) {
        xmin[i] = 1; xmax[i] = n;
        mi[i] = 0; ma[i] = n+1;
    }
    For(i, 1, m) {
        int kind, x, y, v;
        scanf("%d%d%d%d", &kind, &x, &y, &v);
        xmin[v] = max(xmin[v], x);
        xmax[v] = min(xmax[v], y);
        For(j, x, y) if (kind == 1) {
            if (ma[j] == n+1 || ma[j] > v) ma[j] = v;
        } else if (mi[j] == 0 || mi[j] < v) mi[j] = v;
    }
    solve();
}

