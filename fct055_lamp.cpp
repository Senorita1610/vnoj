#include <bits/stdc++.h>
using namespace std;

int N, q;
int x, y;

void lamp() {
	cin >> N >> q;
	vector<bool> ans(N+1, false);
	for(int i = 1; i <= q; i++) {
		cin >> x >> y;
		while(x <= y) {
			ans[x] = !ans[x];
			x++;
		}
	}
	copy(ans.begin()+1, ans.end(), ostream_iterator<int>(cout, " "));
}
int main() {
	lamp();
}

