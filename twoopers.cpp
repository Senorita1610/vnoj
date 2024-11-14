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
#define pb push_back
#define sz(s) int(s.size())
#define reset(f,x) memset(f,x,sizeof(f))
#define all(x) x.begin(), x.end()
#define N 100010

int n;
ll res;
ull h[2][N], mu[N];
char s[2][N];

void init() {
    mu[0] = 1;
    For(i, 1, n) {
        mu[i] = mu[i-1] * 3137;
        h[0][i] = h[0][i-1] * 3137 + int(s[0][i]) - int('A');
        h[1][i] = h[1][i-1] * 3137 + int(s[1][i]) - int('A');
    }
}

ull get(int t, int i, int j) {
    if (i > j) return 0;
    return h[t][j] - h[t][i-1] * mu[j-i+1];
}

int diff(int i, int j, int len) {
    int d = 1, c = len;
    while (d <= c) {
        int mid = (d + c) / 2;
        ull p1 = get(0, i, i + mid-1), p2 = get(0, i + mid, i + len -1);
        ull q1 = get(1, j, j + mid-1), q2 = get(1, j + mid, j + len -1);
        if (p1 != q1 && p2 != q2) return false;
        if (p1 != q1) c = mid - 1;
        else d = mid + 1;
    }
    return true;
}

int main() {
    cin >> (s[0]+1);
    cin >> (s[1]+1);
    n = strlen(s[0]+1);
    init();
    For(i, 1, n) {
        int len = n-i+1;
        ull p1 = get(0, i, n), p2 = get(0, 1, n-len);
        ull q1 = get(1, 1, len), q2 = get(1, len+1, n);
        if (p1 != q1 && p2 != q2) continue;
        else {
            if (p1 == q1 && p2 == q2) res += n;
            else if (p1 != q1 && diff(i, 1, len)) res++;
            else if (p2 != q2 && diff(1, len+1, n-len)) res++;
        }
    }
    cout << res;
}

