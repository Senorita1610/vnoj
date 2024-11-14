#include <bits/stdc++.h>
#define sz(x) ((int)x.size())
#define PB push_back
#define all(x) x.begin(),x.end()
#define i2 array<int,2>
using namespace std;
typedef long long ll;
const int PW = 22;
const int K = 10010;
const int M = 1010;
const int T = 55;
const int BIG = 1000100;
const int oo = int(3e4);
const int ooi = 2e9;
const int CN = 300;
vector<i2> elms;
vector<int> vc;
int k, F[K], L[M], X[T], C[T], cnt = 0, pri[7] = {2, 3, 5, 7, 11, 13, 17};
int mn[BIG], decomp[BIG], m, t, inv[CN];
short gr[CN][CN], ind[BIG], ans[CN][CN][T][PW], f[CN][PW], dp[CN][CN][PW];
 
void amin(int &x, int y){
    x = min(x, y);
}
 
void amin_sh(short &x, short y){
    x = min(x, y);
}
 
struct CHT{
    vector<i2> cht;
    vector<int> fr;
};
 
CHT hull;
 
int divide(int K, int B){
    if ((K < 0 && B < 0) || (K > 0 && B > 0))
        return (B / K) + bool(B % K != 0);
    else return (B / K);
}
 
int get(int xx){
    int res = 1;
    while (xx > 1){
        int cur = mn[xx], kol = 0;
 
        while (xx % cur == 0){
            kol++;
            xx /= cur;
        }
 
        res *= (1 + kol);
    }
    return res;
}
 
int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
 
#ifdef _LOCAL
    freopen("in.txt","r",stdin);
//    freopen("out.txt","w",stdout);
#endif // _LOCAL
 
    fill(mn, mn + BIG, ooi);
 
    for (int i = 2; i < BIG; i++){
        if (mn[i] < ooi) continue;
 
        mn[i] = i;
 
        if (ll(i) * ll(i) >= ll(BIG)) continue;
 
        for (int j = i * i; j < BIG; j += i)
            mn[j] = min(mn[j], i);
    }
 
    for (int i = 1; i < BIG; i++){
        vc.clear();
 
        int xx = i;
 
        while (xx > 1){
            int cur = mn[xx], kol = 0;
 
            while (xx % cur == 0){
                kol++;
                xx /= cur;
            }
 
            vc.PB(kol);
        }
 
        sort(all(vc));
        reverse(all(vc));
 
        for (int it = 0; it < sz(vc); it++)
            for (int cr = 0; cr < vc[it]; cr++)
                xx *= pri[it];
 
        decomp[i] = xx;
 
        if (xx == i) {
            inv[cnt] = i;
            ind[i] = cnt++;
        }
    }
 
    cin >> k;
 
    for (int i = 1; i <= k; i++)
        cin >> F[i];
 
    cin >> m;
 
    for (int i = 0; i < m; i++)
        cin >> L[i];
 
    sort(L, L + m);
 
    cin >> t;
 
    for (int i = 0; i < t; i++)
        cin >> X[i] >> C[i];
 
    for (int i = 0; i < CN; i++)
    for (int j = 0; j < CN; j++)
        gr[i][j] = oo;
 
    for (int i = 1; i < cnt; i++){
        int vl = inv[i];
 
        for (int dv = 1; dv * dv <= vl; dv++){
            if (vl % dv > 0) continue;
 
            int nw = ind[decomp[vl / dv]];
            int up = get(dv);
 
            if (dv > 1)
                amin_sh(gr[nw][i], F[up]);
 
            if (vl / dv != dv){
                nw = ind[decomp[dv]];
                up = get(vl / dv);
 
                amin_sh(gr[nw][i], F[up]);
            }
        }
    }
 
    for (int i = 0; i < cnt; i++){
        fill(f[i], f[i] + PW, oo);
 
        if (i == 0){
            f[i][0] = 0;
            continue;
        }
 
        for (int pr = 0; pr < i; pr++)
            if (gr[pr][i] < oo) {
                for (int len = 0; len < PW; len++)
                    if (f[pr][len] < oo)
                        amin_sh(f[i][len + 1], f[pr][len] + gr[pr][i]);
            }
    }
 
    for (int i = 0; i < cnt; i++)
    for (int j = i; j < cnt; j++){
        if (ll(inv[i]) * ll(inv[j]) >= BIG) continue;
 
        fill(dp[i][j], dp[i][j] + PW, oo);
 
        for (int p1 = 0; p1 < PW; p1++){
            if (f[i][p1] == oo) continue;
 
            for (int p2 = 0; p2 < PW; p2++)
                if (f[j][p2] < oo)
                    amin_sh(dp[i][j][p1 + p2], f[i][p1] + f[j][p2]);
        }
 
        for (int tp = 0; tp < t; tp++){
            fill(ans[i][j][tp], ans[i][j][tp] + PW, oo);
 
            for (int len = 0; len < PW; len++) {
                if (dp[i][j][len] == oo) continue;
 
                int cur = dp[i][j][len];
 
                for (int ad = 0; ad + len < PW; ad++){
                    if (ad > 0)
                        cur += C[tp];
 
                    amin_sh(ans[i][j][tp][ad + len], cur);
                }
            }
        }
    }
 
    int qq; cin >> qq;
 
    for (; qq; qq--){
        int A, B; cin >> A >> B;
 
        if (A % B != 0){
            cout << -m << '\n';
            continue;
        }
 
        elms.clear();
 
        for (int tp = 0; tp < t; tp++)
            if (A % X[tp] == 0 && X[tp] % B == 0){
                int best = ooi;
 
                int b1 = ind[decomp[A / X[tp]]];
                int b2 = ind[decomp[X[tp] / B]];
 
                if (b1 > b2) swap(b1, b2);
 
                for (int len = 0; len < PW; len++)
                    if (dp[b1][b2][len] < oo)
                        amin(best, dp[b1][b2][len] - len * C[tp]);
 
                elms.PB({-C[tp], best});
            }
 
        sort(all(elms));
 
        if (sz(elms) > 0){
            hull.fr.clear();
            hull.cht.clear();
 
            hull.fr.PB(-ooi);
            hull.cht.PB({elms[0][0] * -1, elms[0][1]});
 
            for (int i = 1; i < sz(elms); i++){
                if (elms[i][0] == elms[i - 1][0]) continue;
 
                i2 cur = elms[i];
 
                cur[0] *= -1;
 
                while (sz(hull.cht) > 1){
                    int pos = divide(cur[0] - hull.cht.back()[0], hull.cht.back()[1] - cur[1]);
 
                    if (pos > hull.fr.back()) break;
 
                    hull.cht.pop_back();
                    hull.fr.pop_back();
                }
 
                hull.fr.PB(divide(cur[0] - hull.cht.back()[0], hull.cht.back()[1] - cur[1]));
                hull.cht.PB(cur);
            }
        }
 
        int base = ind[decomp[A / B]], ptr = 0;
 
        ll res = 0;
 
        for (int i = 0; i < m; i++)
            if (L[i] < PW) {
                int cur = ooi;
 
                if (f[base][L[i]] < oo)
                    amin(cur, f[base][L[i]]);
 
                for (int tp = 0; tp < t; tp++)
                    if (A % X[tp] == 0 && X[tp] % B == 0){
                        int b1 = ind[decomp[A / X[tp]]];
                        int b2 = ind[decomp[X[tp] / B]];
 
                        if (b1 > b2) swap(b1, b2);
 
                        if (ans[b1][b2][tp][L[i]] < oo)
                            amin(cur, ans[b1][b2][tp][L[i]]);
                    }
 
                if (cur < ooi)
                    res += cur;
                else res--;
            } else {
                if (sz(elms) == 0)
                    res--;
                else {
                    while (ptr + 1 < sz(hull.cht) && hull.fr[ptr + 1] <= L[i])
                        ptr++;
 
                    res += hull.cht[ptr][1] + hull.cht[ptr][0] * L[i];
                }
            }
 
        cout << res << '\n';
    }
 
    return 0;
}

