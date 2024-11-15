#include<bits/stdc++.h>
using namespace std;
#define FOR(i, a, b) for (int i = (a); i <= (int) (b); ++i)
#define FORD(i, a, b) for (int i = (a); i >= (int) (b); --i)
#define REP(i, a, b) for (int i = (a); i < (int) (b); ++i)
#define each(a, x) for (auto &a : x)
#define fi first
#define se second
#define pb push_back
#define ll long long
#define all(a) a.begin(),a.end()
typedef pair<int, int> pii;
const int N = 3e2;
const int INF = 2106 + 1e9;

int f[N][N];
bool a[N][N];

void SaKaTa() {
	int n, m;
	pii st, en;
	cin >> n >> m >> st.fi >> st.se >> en.fi >> en.se;
	FOR(i, 1, m) {
		int x, y;
		cin >> x >> y;
		a[x][y] = true;
	}
	memset(f, 0x3f, sizeof f);
	f[st.fi][st.se] = 0;
	queue<pii> q;
	q.push(st);
	while(!q.empty()) {
		pii u = q.front();
		q.pop();
		int d = f[u.fi][u.se];
		for(int dx = -1; dx <= 1; dx += 2) {
			for(int dy = -1; dy <= 1; dy += 2) {
				pii v = u;
				while(true) {
					v.fi += dx;
					v.se += dy;
					if(v.fi < 1 || v.fi > n || v.se < 1 || v.se > n) break;
					if(a[v.fi][v.se]) break;
					if(f[v.fi][v.se] > d + 1) {
						f[v.fi][v.se] = d + 1;
						q.push(v);
					}
				}
			}
		}
	}
	cout << (f[en.fi][en.se] <= 1e6 ? f[en.fi][en.se] : -1);
}

int32_t main() {
	ios_base::sync_with_stdio (false);
	cin.tie (nullptr);
	cout.tie (nullptr);
	SaKaTa();
	return 0;
}

