#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

#define ll long long
const ll INF = 1e18 + 1234;

ll N, K; int T;

int na[20], ka[20], ans[20], sum;
ll fsum[21][19 * 10][2];
ll g[21][19 * 10][2];

void fix(ll &x) { if (x > INF) x = INF; }

void prep() {
    memset(fsum, 0, sizeof fsum); memset(g, 0, sizeof g);
    fsum[20][0][0]  = 1;
    for (int i = 19; i >= 1; --i) for (int j = 0; j <= 9 * (19 - i); ++j) for (int k = 0; k < 2; ++k) {
        if (!fsum[i+1][j][k]) continue;
        int r = (!k ? na[i] : 9);
        for (int nxt = 0; nxt <= r; ++nxt) {
            int nok = k; if (!k && nxt < r) nok = 1;
            fsum[i][j + nxt][nok] += fsum[i+1][j][k];
            fix(fsum[i][j + nxt][nok]);
        }
    }

    g[0][0][0] = 1;
    for (int i = 1; i <= 19; ++i) for (int j = 0; j <= 9 * i; ++j) {
        for (int d = 0; d <= 9; ++d) if (j >= d) g[i][j][0] += g[i-1][j-d][0], fix(g[i][j][0]);
        for (int d = 0; d < na[i]; ++d) if (j >= d) g[i][j][1] += g[i-1][j-d][0], fix(g[i][j][1]);
        if (j >= na[i]) g[i][j][1] += g[i-1][j-na[i]][1], fix(g[i][j][1]);
    }
}

int check(int l, int r) {
    for (int i = 19; i > l; --i) if (na[i] > 0) return 1;
    for (int i = l; i >= r; --i) {
        if (na[i] > ans[19 - l + i]) return 1;
        else if (na[i] < ans[19 - l + i]) return -1;
    }
    return 0;
}

void find0() {
    long long res = 0; sum = 0;
    ll tmp = K; int cur = 19;
    while(tmp) --cur, sum += tmp % 10, tmp /= 10;
    tmp = K; for (int i = cur+1; i <= 19; ++i) ka[i] = tmp % 10, tmp /= 10;

    for (int i = 1; i < sum; ++i) res += fsum[1][i][1];

    memset(ans, -1, sizeof ans);
    for (int i = 19; i >= cur; --i) {
        if (sum == 0 && check(19-i, 1)) ++res;
        int l = (i == 19 ? 1 : 0);
        for (int j = l; j < min(sum + 1, ka[i]); ++j) {
            ans[i] = j;
            for (int k = 1; k <= i; ++k) {
                ll cur = 0; int ok = check(k+19-i, k);
                if (ok == 1) cur = g[k-1][sum-j][0];
                if (ok == 0) cur = g[k-1][sum-j][1];
                res += cur;
            }
        }
        ans[i] = ka[i];
        sum -= ka[i];
    }

    cout << res << endl;
}

void find1() {
    sum = 1; ll ff = 0;
    for (int i = 1; i <= 19 * 9; ++i) {
        ff += fsum[1][i][1];
        if (ff >= K) { sum = i; break; }
    }
    ff -= fsum[1][sum][1]; K -= ff; --K;

    memset(ans, -1, sizeof ans);
    for (int i = 19; i >= 1; --i) {
        if (sum == 0 && check(19-i, 1)) --K; if (K < 0) break;
        int l = (i == 19 ? 1 : 0);
        for (int j = l; j <= min(sum, 9); ++j) {
            ll res = 0;
            ans[i] = j;
            for (int k = 1; k <= i; ++k) {
                ll cur = 0; int ok = check(k+19-i, k);
                if (ok == 1) cur = g[k-1][sum-j][0];
                if (ok == 0) cur = g[k-1][sum-j][1];
                res += cur; fix(res);
            }
            if (K >= res) K -= res, ans[i] = -1;
            else break;
        }
        if (ans[i] == -1) break;
        sum -= ans[i];
    }

    ll res = 0;
    for (int i = 19; i >= 1; --i) if (ans[i] != -1) res = res * 10 + ans[i];
    cout << res << endl;
}

void solve() {
    cin >> T >> N >> K; ++N;
    memset(na, 0, sizeof na);
    memset(ka, 0, sizeof ka);
    ll tmp = N; for (int i = 1; i <= 19; ++i) na[i] = tmp % 10, tmp /= 10;
    prep();

    if (T == 1) find1();
    else find0();
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int t; cin >> t;
    while(t--)
        solve();
}

