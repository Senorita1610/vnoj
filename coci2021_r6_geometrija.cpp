#include <bits/stdc++.h>
 
using std::vector;
using std::array;
using std::pair;
using std::tuple;
 
using i64 = std::int64_t;
 
struct Point {
    int x, y;
    Point(int x = 0, int y = 0) : x(x), y(y) {}
    int belongs() const {
        if (x >= 0 and y >= 0) return 0;
        if (x < 0 and y > 0) return 0;
        return 1;
    }
    friend Point operator+(const Point& p, const Point& q) {
        return Point(p.x + q.x, p.y + q.y);
    }
    friend Point operator-(const Point& p, const Point& q) {
        return Point(p.x - q.x, p.y - q.y);
    }
    friend i64 cross(const Point& p, const Point& q) {
        return (i64)p.x * q.y - (i64)p.y * q.x;
    }
};
 
int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int N;
    std::cin >> N;
    vector<Point> P(N);
    for (auto& [x, y] : P) {
        std::cin >> x >> y;
    }
    vector left(N, vector<int>(N));
    vector right(N, vector<int>(N));
    for (int pivot = 0; pivot < N; ++pivot) {
        vector<int> ord;
        ord.reserve(N - 1);
        for (int i = 0; i < N; ++i) {
            if (i != pivot) {
                ord.push_back(i);
                P[i] = P[i] - P[pivot];
            }
        }
        std::sort(ord.begin(), ord.end(), [&](const int i, const int j) {
            if (P[i].belongs() != P[j].belongs()) return P[i].belongs() < P[j].belongs();
            return cross(P[i], P[j]) > 0;
        });
        const auto get = [&](const int i) {
            return P[ord[i >= N - 1 ? i - (N - 1) : i]];
        };
        vector<int> half(2 * (N - 1));
        for (int i = 0, r = 0; i < N - 1; ++i) {
            while (r < i + N - 1 and cross(get(i), get(r)) >= 0) {
                r += 1;
            }
            half[i] = r;
            half[i + N - 1] = r + N - 1;
        }
        int sum_l = 0, sum_r = 0;
        for (int i = 0, r_l = 0, r_r = 0; i < N - 1; ++i) {
            while (r_l < half[i]) {
                sum_l += half[r_l];
                sum_r -= half[r_l];
                r_l += 1;
            }
            while (r_r < i + N - 1) {
                sum_r += half[r_r];
                r_r += 1;
            }
            const int above = half[i] - i;
            const int below = (N - 1) - above;
            left[pivot][ord[i]] = sum_l - above * half[i];
            right[pivot][ord[i]] = sum_r - below * (i + N);
            sum_l -= half[i];
        }
        for (const int i : ord) {
            P[i] = P[i] + P[pivot];
        }
    }
    int ans = 0;
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < i; ++j) {
            if (left[i][j] == right[j][i]) {
                ans += 1;
            }
        }
    }
    std::cout << ans << '\n';
    return 0;
}

