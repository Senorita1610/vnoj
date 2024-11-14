#include <bits/stdc++.h>
#define X1(k) (sb[k])
#define Y1(k) (sb[k] * sb[k] - f[i - 1][k])
#define X2(k) (sa[k])
#define Y2(k) (sa[k] * sa[k] - f[k][j - 1])
const int N = 1005;
typedef long long ll;
using namespace std;
ll a[N], b[N], q1[N][N], q2[N][N], sa[N], sb[N], h1[N], h2[N], t1[N], t2[N];
ll f[N][N], ans = LLONG_MIN, n;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n;

    for (int i = 1; i <= n; i++)
        cin >> a[i], sa[i] = sa[i - 1] + a[i];

    for (int i = 1; i <= n; i++)
        cin >> b[i], sb[i] = sb[i - 1] + b[i];

    for (int i = 1; i <= n; i++)
        h1[i] = h2[i] = 1, f[i][0] = -sa[i] * sa[i], f[0][i] = -sb[i] * sb[i];

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            f[i][j] = a[i] * b[j] - sa[i - 1] * sa[i - 1] - sb[j - 1] * sb[j - 1];

            while (h1[i] < t1[i] &&
                    (Y1(q1[h1[i] + 1][i]) - Y1(q1[h1[i]][i])) <= (X1(q1[h1[i] + 1][i]) - X1(q1[h1[i]][i])) * 2 * sb[j - 1])
                h1[i]++;

            if (i > 1)
                f[i][j] = max(f[i][j], f[i - 1][q1[h1[i]][i]] + a[i] * b[j] - (sb[j - 1] - sb[q1[h1[i]][i]]) * (sb[j - 1] - sb[q1[h1[i]][i]]));

            while (h1[i] < t1[i] &&
                    (Y1(q1[t1[i]][i]) - Y1(q1[t1[i] - 1][i])) * (X1(j) - X1(q1[t1[i]][i])) >= (Y1(j) - Y1(q1[t1[i]][i])) * (X1(q1[t1[i]][i]) - X1(q1[t1[i] - 1][i])))
                t1[i]--;

            q1[++t1[i]][i] = j;

            while (h2[j] < t2[j] &&
                    (Y2(q2[h2[j] + 1][j]) - Y2(q2[h2[j]][j])) <= (X2(q2[h2[j] + 1][j]) - X2(q2[h2[j]][j])) * 2 * sa[i - 1])
                h2[j]++;

            if (j > 1)
                f[i][j] = max(f[i][j], f[q2[h2[j]][j]][j - 1] + a[i] * b[j] - (sa[i - 1] - sa[q2[h2[j]][j]]) * (sa[i - 1] - sa[q2[h2[j]][j]]));

            while (h2[j] < t2[j] &&
                    (Y2(q2[t2[j]][j]) - Y2(q2[t2[j] - 1][j])) * (X2(i) - X2(q2[t2[j]][j])) >= (Y2(i) - Y2(q2[t2[j]][j])) * (X2(q2[t2[j]][j]) - X2(q2[t2[j] - 1][j])))
                t2[j]--;

            q2[++t2[j]][j] = i;
            ans = max(ans, f[i][j] - (sa[n] - sa[i]) * (sa[n] - sa[i]) - (sb[n] - sb[j]) * (sb[n] - sb[j]));
        }
    }

    printf("%lld\n", ans);
    return 0;
}

