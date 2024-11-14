#include <bits/stdc++.h>
using namespace std;
 
 
const int MAX = 2001;
 
int n, m;
char grid[MAX][MAX];
bool vis[MAX][MAX];
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
 
    cin >> n >> m;
    for (int i = 0; i < n; ++i)
    cin >> grid[i];
    vector<pair<int, int>> act, next;
    for (act.push_back({0, 0}); !act.empty(); act = next) {
        pair<int, int> p = act.back();
        cout << grid[p.first][p.second];
        char mn = 'z';
        for (pair<int, int> pt : act) {
            int dx = 1, dy = 0;
            for (int i = 0; i < 2; ++i) {
                swap(dx, dy);
                int nx = pt.first + dx;
                int ny = pt.second + dy;
                if (nx >= n || ny >= m) continue;
                mn = min(mn, grid[nx][ny]);
            }
        }
        next.clear();
        for (pair<int, int> pt : act) {
            int dx = 1, dy = 0;
                for (int i = 0; i < 2; ++i) {
                    swap(dx, dy);
                    int nx = pt.first + dx;
                    int ny = pt.second + dy;
                    if (nx >= n || ny >= m) continue;
                    if (vis[nx][ny]) continue;
                    if (grid[nx][ny] == mn) {
                        next.push_back({nx, ny});
                        vis[nx][ny] = 1;
                    }
                }
        }
    }
  cout << '\n';
  return 0;
}

