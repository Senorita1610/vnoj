#include <bits/stdc++.h>
 
using std::vector;
using std::array;
using std::pair;
using std::tuple;
 
using i64 = std::int64_t;
constexpr i64 inf = std::numeric_limits<i64>::max() / 2;
 
bool setmin(i64& x, const i64 y) {
    if (x > y) {
        x = y;
        return true;
    }
    return false;
}
 
template <class T> using Heap = std::priority_queue<T, vector<T>, std::greater<>>;
 
int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int N, M;
    std::cin >> N >> M;
    vector<std::string> U(M), V(M);
    vector<int> C(M);
    for (int i = 0; i < M; ++i) {
        std::cin >> U[i] >> V[i] >> C[i];
    }
    vector<std::string> S;
    S.reserve(2 * M);
    std::copy(U.begin(), U.end(), std::back_inserter(S));
    std::copy(V.begin(), V.end(), std::back_inserter(S));
    std::sort(S.begin(), S.end());
    S.erase(std::unique(S.begin(), S.end()), S.end());
    vector<vector<pair<int, int>>> graph(N);
    for (int i = 0; i < M; ++i) {
        const int u = std::lower_bound(S.begin(), S.end(), U[i]) - S.begin();
        const int v = std::lower_bound(S.begin(), S.end(), V[i]) - S.begin();
        graph[u].emplace_back(v, C[i]);
    }
    vector dist(N, vector<i64>(N, inf));
    for (int src = 0; src < N; ++src) {
        auto& vec = dist[src];
        Heap<pair<i64, int>> heap;
        const auto push = [&](const int u, const i64 d) {
            if (setmin(vec[u], d)) {
                heap.emplace(d, u);
            }
        };
        push(src, 0);
        while (!heap.empty()) {
            const auto [d, u] = heap.top();
            heap.pop();
            if (vec[u] < d) {
                continue;
            }
            for (const auto& [v, c] : graph[u]) {
                push(v, d + c);
            }
        }
    }
    int Q;
    std::cin >> Q;
    while (Q--) {
        std::string s, t;
        std::cin >> s >> t;
        const int u = std::lower_bound(S.begin(), S.end(), s) - S.begin();
        const int v = std::lower_bound(S.begin(), S.end(), t) - S.begin();
        if (dist[u][v] == inf) {
            std::cout << "Roger\n";
        } else {
            std::cout << dist[u][v] << '\n';
        }
    }
    return 0;
}

