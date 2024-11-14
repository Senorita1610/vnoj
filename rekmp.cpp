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
#define N 100001

int n, next[N], x[N], kmp[N];
bool dd[16];

int main() {
    scanf("%d", &n);
    For(i, 1, n) scanf("%d", &next[i]);
    x[1] = 0;
    For(i, 2, n) {
        if (next[i]) x[i] = x[next[i]];
        else {
            x[i] = -1;
            reset(dd, true);
            dd[0] = false;
            int j = next[i-1];
            while (j) {
                dd[x[j+1]] = false;
                j = next[j];
            }
            For(ch, 0, 15) if (dd[ch]) {
                x[i] = ch; break;
            }
            if (x[i] < 0) { cout << -1; return 0; }
        }
    }

    kmp[1] = 0;
    For(i, 2, n) {
        int j = kmp[i-1];
        while (j && x[i] != x[j+1]) j = kmp[j];
        if (x[i] == x[j+1]) kmp[i] = j+1; else kmp[i] = 0;
        if (kmp[i] != next[i]) { cout << -1; return 0; }
    }
    For(i, 1, n) if (x[i] < 10) cout << x[i]; else cout << char(x[i]-10+int('A'));
}

