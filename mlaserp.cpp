#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <utility>
#include <vector>
using namespace std;

#define sz size()
#define pb push_back
#define mp make_pair

typedef long long ll;
typedef pair<int, int> ii;

char grid[110][110];

class Compare {
public:
  bool operator()(pair<ii, ii> a,
                  pair<ii, ii> b) { 
    return a.second.second > b.second.second;
  }
};

int w, h;
int dist[110][110][4];
ii src, dest;
void dijkstra() {
  priority_queue<pair<ii, ii>, vector<pair<ii, ii>>, Compare> pq;
  for (int i = 0; i < 4; i++) {
    pq.push(mp(src, mp(i, 0)));
    dist[src.first][src.second][i] = 0;
  }
  while (!pq.empty()) {
    int y = pq.top().first.first;
    int x = pq.top().first.second;
    int direc = pq.top().second.first;
    int cost = pq.top().second.second;
    pq.pop();
    if (direc == 0) {
      if (x + 1 < w && grid[y][x + 1] != '*' && dist[y][x + 1][direc] > cost) {
        dist[y][x + 1][direc] = cost;
        pq.push(mp(mp(y, x + 1), mp(direc, cost)));
      }
      if (y - 1 >= 0 && grid[y - 1][x] != '*' && dist[y - 1][x][3] > cost + 1) {
        dist[y - 1][x][3] = cost + 1;
        pq.push(mp(mp(y - 1, x), mp(3, cost + 1)));
      }
      if (y + 1 < h && grid[y + 1][x] != '*' && dist[y + 1][x][1] > cost + 1) {
        dist[y + 1][x][1] = cost + 1;
        pq.push(mp(mp(y + 1, x), mp(1, cost + 1)));
      }
    }
    if (direc == 1) {
      if (y + 1 < h && grid[y + 1][x] != '*' && dist[y + 1][x][direc] > cost) {
        dist[y + 1][x][direc] = cost;
        pq.push(mp(mp(y + 1, x), mp(direc, cost)));
      }
      if (x - 1 >= 0 && grid[y][x - 1] != '*' && dist[y][x - 1][2] > cost + 1) {
        dist[y][x - 1][2] = cost + 1;
        pq.push(mp(mp(y, x - 1), mp(2, cost + 1)));
      }
      if (x + 1 < w && grid[y][x + 1] != '*' && dist[y][x + 1][0] > cost + 1) {
        dist[y][x + 1][0] = cost + 1;
        pq.push(mp(mp(y, x + 1), mp(0, cost + 1)));
      }
    }
    if (direc == 2) {
      if (x - 1 >= 0 && grid[y][x - 1] != '*' && dist[y][x - 1][direc] > cost) {
        dist[y][x - 1][direc] = cost;
        pq.push(mp(mp(y, x - 1), mp(direc, cost)));
      }
      if (y - 1 >= 0 && grid[y - 1][x] != '*' &&
          dist[y - 1][x][3] > cost + 1) {
        dist[y - 1][x][3] = cost + 1;
        pq.push(mp(mp(y - 1, x), mp(3, cost + 1)));
      }
      if (y + 1 < h && grid[y + 1][x] != '*' &&
          dist[y + 1][x][1] > cost + 1) {
        dist[y + 1][x][1] = cost + 1;
        pq.push(mp(mp(y + 1, x), mp(1, cost + 1)));
      }
    }
    if (direc == 3) { // NORTH
      if (y - 1 >= 0 && grid[y - 1][x] != '*' && dist[y - 1][x][direc] > cost) {
        dist[y - 1][x][direc] = cost;
        pq.push(mp(mp(y - 1, x), mp(direc, cost)));
      }
      if (x - 1 >= 0 && grid[y][x - 1] != '*' &&
          dist[y][x - 1][2] > cost + 1) {
        dist[y][x - 1][2] = cost + 1;
        pq.push(mp(mp(y, x - 1), mp(2, cost + 1)));
      }
      if (x + 1 < w && grid[y][x + 1] != '*' &&
          dist[y][x + 1][0] > cost + 1) {
        dist[y][x + 1][0] = cost + 1;
        pq.push(mp(mp(y, x + 1), mp(0, cost + 1)));
      }
    }
  }
}

int main() {
  scanf("%d%d", &w, &h);
  for (int i = 0; i < h; i++) {
    scanf("%s", grid[i]);
  }
  src = mp(-1, -1);
  for (int i = 0; i < h; i++) {
    for (int j = 0; j < w; j++) {
      for (int k = 0; k < 4; k++)
        dist[i][j][k] = 1e5;
      if (grid[i][j] == 'C') {
        if (src.first == -1) {
          src = mp(i, j);
        } else {
          dest = mp(i, j);
        }
      }
    }
  }
  dijkstra();
  int ans = 1e5;
  for (int i = 0; i < 4; i++)
    if (dist[dest.first][dest.second][i] < ans)
      ans = dist[dest.first][dest.second][i];

  printf("%d\n", ans);
  return 0;
}

