#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using Config = array<ll, 4>;
enum PieceType { TL, TR, BR, BL };

Config operator-(Config u, const Config& v) {
    for (int i = 0; i < 4; ++i) {
        u[i] -= v[i];
    }
    return u;
}

Config build_L_piece(PieceType type, int size) {
    Config ans;
    if (size == 1) {
        ans = {1, 0, 0, 0};
    } else {
        size -= 2;
        ll pw2 = 1ll << size;
        ll pw4 = pw2 << size;
        ans = {pw4 + pw2, pw4, pw4 - pw2, pw4};
    }
    rotate(ans.rbegin(), ans.rbegin() + type, ans.rend());
    return ans;
}

bool find_ans(int& r, int& c, int k, Config conf) {
    if (k == 0) {
        for (int i = 0; i < 4; ++i) if (conf[i]) return false;
        return true;
    }

    if (*min_element(conf.begin(), conf.end()) < 0) return false;
    PieceType big_piece;
    for (auto x: {TL, TR, BR, BL}) {
        auto x180 = (PieceType)(x ^ 2);
        // these 2 below might not be x90 and x270, but their roles might be swapped
        // but that is not important nontheless
        auto x90 = (PieceType)(x ^ 1);
        auto x270 = (PieceType)(x ^ 3);
        if (conf[x] - conf[x180] > abs(conf[x90] - conf[x270])) {
            big_piece = x;
            break;
        }
    }
    int half = 1 << (k - 1);
    if (big_piece == BL or big_piece == BR) r += half;
    if (big_piece == TR or big_piece == BR) c += half;
    return find_ans(r, c, k - 1, conf - build_L_piece(big_piece, k));
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int ntest;
    cin >> ntest;
    while (ntest--) {
        int k;
        cin >> k;
        Config conf;
        for (int i = 0; i < 4; ++i) cin >> conf[i];
        ll sum = conf[0] + conf[1] + conf[2] + conf[3];
        if (sum != ((1ll << k << k) - 1) / 3) {
            cout << "-1\n";
            continue;
        }
        int ans_r = 0, ans_c = 0;
        if (find_ans(ans_r, ans_c, k, conf)) {
            cout << ans_r << ' ' << ans_c << '\n';
        } else {
            cout << "-1\n";
        }
    }

    return 0;
}

