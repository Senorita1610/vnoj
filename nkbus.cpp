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
#define reset(f, x) memset(f, x, sizeof(f))
#define all(x) x.begin(), x.end()
#define two(x) (1 << x)
#define bit(x, i) ((x >> i) & 1)
#define onbit(x, i) (x | (1 << i))

vector<int> go;
int n, m, k;

int main() {
    scanf("%d%d", &n, &m);
    int t = 0;
    For(i, 1, n) {
        int x, temp, num;
        scanf("%d%d", &temp, &num);
        k += num;
        For(i, 1, num) {
            scanf("%d", &x);
            go.pb(max(0, x - t));
        }
        t += temp;
    }
    sort(all(go));
    cout << t + go[min(m, k)-1];
}

