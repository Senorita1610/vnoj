#include <bits/stdc++.h>
using namespace std;
#define rep(ii,aa,bb) for(re int ii = aa; ii <= bb; ii++)
#define Rep(ii,aa,bb) for(re int ii = aa; ii >= bb; ii--)
typedef long long ll;
typedef unsigned long long ull;
typedef double db;
typedef pair<int, int> PII;
const int maxn = 205;
namespace IO_ReadWrite {
	#define re register
	#define gg (p1 == p2 && (p2 = (p1 = _buf) + fread(_buf, 1, 1<<21, stdin), p1 == p2) ? EOF :*p1++)
	char _buf[1<<21], *p1 = _buf, *p2 = _buf;
	template <typename T>
	inline void read(T &x){
		x = 0; re T f=1; re char c = gg;
		while(c > 57 || c < 48){if(c == '-') f = -1;c = gg;}
		while(c >= 48 &&c <= 57){x = (x<<1) + (x<<3) + (c^48);c = gg;}
		x *= f;return;
	}
	inline void ReadChar(char &c){
		c = gg;
		while(!isalpha(c)) c = gg;
	}
	template <typename T>
	inline void write(T x){
		if(x < 0) putchar('-'), x = -x;
		if(x > 9) write(x/10);
		putchar('0' + x % 10);
	}
	template <typename T>
	inline void writeln(T x){write(x); putchar('\n');}
}
using namespace IO_ReadWrite;
int dx[4] = {0, 1, 0, -1},
	dy[4] = {1, 0, -1, 0};//right, down, left, up
int N, M, K, turns[maxn][maxn][4][8];
char mp[maxn][maxn][8];
ll date[maxn][maxn][4][8];
int main () {
	scanf("%d%d%d", &N, &K, &M);
	rep(i, 1, M) {
		int x, y;
		scanf("%d%d", &x, &y);
		scanf("%s", mp[x][y]);
	}
	ll ans = 0;
	int x = 1, y = 1, dir = 0, day = 0, k = 0;
	while(1) {
		if(mp[x][y][day] == 'L') dir = (dir + 3) % 4, k ++;
		if(mp[x][y][day] == 'R') dir = (dir + 1) % 4, k ++;
		int nx = x + dx[dir], ny = y + dy[dir];
		if(nx < 1 || nx > N || ny < 1 || ny > N) dir = (dir + 2) % 4, k ++;
		if(date[x][y][dir][day]) {
			int newK = k - turns[x][y][dir][day];
			int left = K - k;
			ans += (left / newK) * (ans - date[x][y][dir][day]);
			k += (left / newK) * newK;
		}
		date[x][y][dir][day] = ans;
		turns[x][y][dir][day] = k;
		if(k >= K) break;
		x = x + dx[dir], y = y + dy[dir];
		ans ++;
		if(++day >= 7) day = 0;
	}
	writeln(ans);
	return 0;
}

