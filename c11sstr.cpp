#include <bits/stdc++.h>
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
#define N 1001
#define inf 1000000000000LL

int n, a[N], pos[N], s[N], b[N], p[N];
ll k, f[N][26];
bool check[N][26], flag;

void init() {
    b[1] = 0;
    For(i, 2, n) {
        if (pos[a[i-1]+1] < pos[a[i]+1]) b[i] = 0;
        else b[i] = 1;
        p[i] = p[i-1] + b[i];
    }
}

ll tinh(int i, int x) {
    if (s[a[i-1]] != -1 && x != s[a[i-1]]) return 0;
    if (i > n) return 1;
    if (check[i][x]) return f[i][x];
    ll res = 0;
    int d = x + b[i];
    For(ch, d, 25) {
        res += tinh(i+1, ch);
        if (res > inf) {
            res = inf; break;
        }
    }
    check[i][x] = true;
    f[i][x] = res;
    return f[i][x];
}

void cal(int i, ll k) {
    if (i > n) return;
    For(ch, p[pos[i]], 25) {
        s[i] = ch;
        reset(check, false);
        ll y = tinh(1, 0);
        if (y < k) k -= y;
        else {
            cal(i+1, k);
            return;
        }
    }
    flag = false;
}

int main() {
    cin >> n >> k;
    For(i, 1, n) {
        scanf("%d", &a[i]);
        pos[a[i]] = i; s[i] = -1;
    }
    init();
    flag = true;
    cal(1, k);
    if (flag) For(i, 1, n) cout << char(s[i]+int('a'));
    else cout << -1;
}

