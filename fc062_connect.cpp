#include <iostream>
#include <algorithm>
#include <cstring>

const int LEN = 1e4 + 1;
struct E {
	int a, w;
	bool operator<(const E& o) const { return a < o.a; }
} e[LEN];
int N;

int dp[LEN];
int dfs(int i) {
	if (i >= N) return 0;
	int& ref = dp[i];
	if (~ref) return ref;
	
	ref = N - i - 1;
	int l = e[i].a;
	int cnt = 0;
	for (int k = i + 1; k < N; ++k) {
		int r = l + e[k].w;
		if (r <= e[k].a) ref = std::min(ref, cnt + dfs(k));
		if (e[k].a < l || r < e[k].a) cnt++;
		l = r;
	}
	ref = std::min(ref, cnt);
	return ref;
}

int main() {
	std::cin >> N;
	for (int i = 0; i < N; ++i) std::cin >> e[i].a;
	for (int i = 0; i < N; ++i) std::cin >> e[i].w;
	std::sort(e, e + N);

	int ret = N;
	memset(dp, -1, sizeof dp);
	for (int i = N - 1; i >= 0; --i) 
		ret = std::min(ret, i + dfs(i));
	std::cout << ret;
}

