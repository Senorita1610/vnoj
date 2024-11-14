#pragma GCC optimize("O3")
#include <bits/stdc++.h>
 
template<int64_t p, int64_t m>
struct hash_string {
    static std::vector<int64_t> power;
    std::vector<int64_t> p_hash;
    hash_string(const std::string& s) : p_hash(s.size()+1, 0) {
        for (int i = 0; i < (int)s.size(); i++) {
            p_hash[i+1] = (p_hash[i] * p + s[i]) % m;
        }
    }
    int64_t pow(int i) {
        while (i >= (int)power.size()) {
            auto val = power.back();
            val = val * p % m;
            power.push_back(val);
        }
        return power[i];
    }
    int64_t pow(int64_t x, int i) {
        if (i == 0) return 1;
        auto ret = pow(x, i/2);
        ret = ret * ret % m;
        if (i & 1) ret = ret * x % m;
        return ret;
    }
    int64_t pow_sum(int64_t x, int i) {
        if (i <= 1) return 1;
        auto ret = pow_sum(x, i/2);
        ret = (1 + pow(x, i/2)) % m * ret % m;
        if (i & 1) ret = (ret * x % m + 1) % m;
        return ret;
    }
    int64_t hash(int l, int r) {
        auto ret = p_hash[r+1] - p_hash[l] * pow(r-l+1) % m;
        ret = (ret + m) % m;
        return ret;
    }
    int64_t hash(int l, int r, int k) {
        int n = r - l + 1;
        static int n_ = 0;
        static int k_ = 0;
        static int64_t pow_sum_ = 0;
        if (n != n_ || k != k_) {
            n_ = n;
            k_ = k;
            pow_sum_ = pow_sum(pow(n), k/n);
        }
        int64_t ret = 0;
        if (k / n != 0) {
            ret = hash(l, r) * pow_sum_ % m;
        }
        if (k % n != 0) {
            ret = ret * pow(k % n) % m + hash(l, l + k % n - 1);
            ret %= m;
        }
        return ret;
    }
};
 
template<int64_t p, int64_t m>
std::vector<int64_t> hash_string<p, m>::power {1};
 
struct hash_string2 {
    hash_string<9973, 1000000009> s1;
    hash_string<9973, 1000000007> s2;
    hash_string2(const std::string& s) : s1(s), s2(s) {}
    int64_t hash(int l, int r, int k) {
        return (s1.hash(l, r, k) << 32) | s2.hash(l, r, k);
    }
};
 
constexpr auto max = 501;
bool visited[max][max][4];
 
int main() {
    std::cin.tie(0)->sync_with_stdio(0);
    int n, m, k;
    std::cin >> n >> m >> k;
    std::vector<std::string> v(n);
    for (auto &s : v) {
        std::cin >> s;
    }
    std::vector<int64_t> result;
    auto update = [&](std::pair<int, int> start, int t) -> void {
        const std::array<std::pair<int, int>, 4> direction {{{1, 0}, {1, 1}, {1, -1}, {0, 1}}};
        auto [row, col] = start;
        if (visited[row][col][t]) return;
        const auto [dr, dc] = direction[t];
        std::string s;
        while (!visited[row][col][t]) {
            visited[row][col][t] = true;
            s.push_back(v[row][col]);
            row = (row + dr + n) % n;
            col = (col + dc + m) % m;
        }
        int sz = int(std::size(s));
        s += s;
        hash_string2 hs(s);
        for (int i = 0; i < sz; i++) {
            auto hash = hs.hash(i, i+sz-1, k);
            result.push_back(hash);
        }
        std::reverse(s.begin(), s.end());
        hash_string2 hs_reversed(s);
        for (int i = 0; i < sz; i++) {
            auto hash = hs_reversed.hash(i, i+sz-1, k);
            result.push_back(hash);
        }
    };
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            for (int t = 0; t < 4; t++) {
                update({i, j}, t);
            }
        }
    }
    int64_t p = 0;
    int64_t q = 64LL * n * n * m * m;
    std::sort(result.begin(), result.end());
    int64_t count = 1;
    for (int i = 1; i < (int)result.size(); i++) {
        if (result[i-1] == result[i]) {
            ++count;
        } else {
            p += count * count;
            count = 1;
        }
    }
    p += count * count;
    auto g = std::gcd(p, q);
    std::cout << p/g << '/' << q/g << '\n';
}

