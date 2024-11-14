#include <algorithm>
#include <cstdio>
#include <iostream>
#include <vector>

#define N 55
#define P 10007
#define foc(x, a) for (auto x = a.begin(); x != a.end(); x++)

using namespace std;

typedef pair<int, int> PII;
typedef vector<PII>::iterator ITR;

int n, m, K, Ans;
char A[100];
int f[N][N][N][2], g[N][N][N];
vector<PII> load[N][30], unload[N][30];
vector<PII> road[N], iroad[N];

int main() {
  cin >> n >> m >> K;
  cin.ignore();
  for (int i = 1; i <= m; i++) {
    cin.getline(A, 100);
    int x, y, cnt;
    char c;
    cnt = sscanf(A, "%d %d %c", &x, &y, &c);
    if (cnt == 2) {
      road[x].push_back(PII(x, y));
      iroad[x].push_back(PII(x, y));
    } else if (c >= 'A' && c <= 'Z') {
      load[x][c - 'A'].push_back(PII(x, y));
      iroad[x].push_back(PII(x, y));
    } else
      unload[y][c - 'a'].push_back(PII(x, y));
  }

  for (int i = 1; i <= n; i++) f[i][i][0][0] = f[i][i][0][1] = 1;

  for (int k = 1; k <= K; k++) {
    if (k >= 2) {
      for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
          for (int t = 0; t < 26; t++) {
            for (auto x = load[i][t].begin(); x != load[i][t].end(); x++) {
              for (auto y = unload[j][t].begin(); y != unload[j][t].end();
                   y++) {
                (g[i][j][k] += f[x->second][y->first][k - 2][0]) %= P;
              }
            }
          }
        }
      }
    }

    for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= n; j++) {
        for (int s = 0; s < 2; s++) {
          if (s) {
            for (auto x = iroad[i].begin(); x != iroad[i].end(); x++) {
              (f[i][j][k][s] += f[x->second][j][k - 1][s]) %= P;
            }
          } else {
            for (auto x = road[i].begin(); x != road[i].end(); x++) {
              (f[i][j][k][s] += f[x->second][j][k - 1][s]) %= P;
            }
          }
        }
      }
    }

    for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= n; j++) {
        for (int s = 0; s < 2; s++) {
          for (int x = 1; x <= n; x++) {
            for (int t = 2; t <= k; t++) {
              (f[i][j][k][s] += g[i][x][t] * f[x][j][k - t][s]) %= P;
            }
          }
        }
      }
    }

    (Ans += f[1][n][k][1]) %= P;
  }

  cout << Ans << endl;
  return 0;
}

