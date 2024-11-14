#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> ii;
typedef pair<long long, int> lli;
typedef long long ll;
typedef unsigned long long ull;

#define For(i,a,b) for(int i=a;i<=b;i++)
#define Rep(i,a,b) for(int i=a;i>=b;i--)
#define REP(i, n) for(int i = 0; i < n; i++)
#define FOR(i, f) for(__typeof(f.begin()) i = f.begin(); i != f.end(); i++)
#define fi first
#define se second
#define pb push_back
#define sz(s) int(s.size())
#define reset(f, x) memset(f, x, sizeof(f))
#define all(x) x.begin(), x.end()
#define two(x) (1LL << x)
#define getbit(x, i) ((x >> (i-1)) & 1LL)
#define onbit(x, i) (x | (1LL << (i-1)))
#define offbit(x, i) (x & ~(1 << (i-1)))
#define N 310

int n;

int main() {
    cin >> n;
    if (n == 3) {
        cout << 1 << endl;
        cout << "1 1 1\n1 1 1";
    } else if (n <= 6) {
        cout << 2 << endl;
        if (n == 4) cout << "1 1 1 1\n1 2 1 2";
        else if (n == 5) cout << "1 1 2 2 2\n2 1 2 1 2";
        else cout << "1 1 1 2 2 2\n1 2 1 2 1 2";
    } else {
        cout << 3 << endl;
        For(i, 1, n) cout << (i % 2) + 1 << ' '; cout << endl;
        For(i, 1, n) cout << 3 << ' ';
    }
}

