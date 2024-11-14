#include <bits/stdc++.h>
using namespace std;
 
const int D[] = {0, 1, 0, -1};
const int MAGIC = 620;
const int C_MAX = 1e5;
const int N = 2e5;
 
vector<int> neighbors[N], members[N];
int color[N], leader[N];
 
vector<set<int>> neighbors_by_color[N];
bool in_vector[N];
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
 
    int n, m; cin >> n >> m;
 
    for (int i = 0; i < n * m; ++i) cin >> color[i];
 
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            int id = i * m + j;
            leader[id] = id;
            members[id].push_back(id);
            for (int dir = 0; dir < 4; ++dir) {
                int i_new = i + D[dir], j_new = j + D[(dir + 1) % 4];
                if (0 <= i_new && i_new < n && 0 <= j_new && j_new < m) {
                    neighbors[id].push_back(i_new * m + j_new);
                }
            }
        }
    }
 
    set<int> big_groups;
 
    auto normalize = [&](int a) {
        vector<int> neighbors_new;
        for (auto b : neighbors[a]) {
            b = leader[b];
            if (leader[b] != a && !in_vector[b]) {
                neighbors_new.push_back(b);
                in_vector[b] = true;
            }
        }
        swap(neighbors[a], neighbors_new);
    };
 
    auto update = [&](int a) {
        if ((int) members[a].size() >= MAGIC) {
            for (auto b : big_groups) {
                if (a != b && neighbors_by_color[a][color[b]].count(b))
                    neighbors_by_color[b][color[a]].insert(a);
            }
        } else {
            normalize(a);
            for (auto b : big_groups) {
                if (in_vector[b])
                    neighbors_by_color[b][color[a]].insert(a);
            }
            for (auto b : neighbors[a]) in_vector[b] = false;
        }
    };
 
    auto merge = [&](int a, int b) {
        if (members[a].size() < members[b].size()) swap(a, b);
 
        if ((int) members[a].size() < MAGIC && (int) (members[a].size() + members[b].size()) >= MAGIC) {
            neighbors_by_color[a].resize(C_MAX);
            for (auto u : neighbors[a])
                neighbors_by_color[a][color[leader[u]]].insert(leader[u]);
            big_groups.insert(a);
        }
 
        if ((int) (members[a].size() + members[b].size()) >= MAGIC) {
            for (auto u : neighbors[b])
                neighbors_by_color[a][color[leader[u]]].insert(leader[u]);
            neighbors_by_color[b].clear();
            big_groups.erase(b);
        }
 
        for (auto i : members[b]) leader[i] = a;
 
        members[a].insert(members[a].end(), members[b].begin(), members[b].end());
        members[b].clear();
 
        neighbors[a].insert(neighbors[a].end(), neighbors[b].begin(), neighbors[b].end());
        neighbors[b].clear();
    };
 
    auto fill = [&](int a, int c) {
        a = leader[a];
 
        while (true) {
            if ((int) members[a].size() < MAGIC) {
                bool merged = false;
                auto initial_neighbors = neighbors[a];
                for (auto b : initial_neighbors) {
                    b = leader[b];
                    if (b != a && color[b] == c) {
                        merged = true;
                        merge(a, b);
                        a = leader[a];
                    }
                }
                if (!merged) break;
            } else {
                if (neighbors_by_color[a][c].empty()) break;
 
                int b = *neighbors_by_color[a][c].begin();
                neighbors_by_color[a][c].erase(b);
                b = leader[b];
 
                if (b != a && color[b] == c) {
                    merge(a, b);
                    a = leader[a];
                }
            }
        }
 
        color[a] = c;
        update(a);
    };
 
    for (int i = 0; i < n * m; ++i)
        fill(i, color[i]);
 
    int q; cin >> q;
 
    while (q--) {
        int i, j, c; cin >> i >> j >> c; --i, --j;
        fill(i * m + j, c);
    }
 
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cout << color[leader[i * m + j]] << " ";
        }
        cout << "\n";
    }
}

