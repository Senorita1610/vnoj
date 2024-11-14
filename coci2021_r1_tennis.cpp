#include <bits/stdc++.h>
 
using namespace std;
 
#define nl '\n'
#define pb push_back
 
using ll = long long;
 
template<class T> using V = vector<T>;
using vi = V<int>;
using vl = V<ll>;
 
int main() {
	cin.tie(0)->sync_with_stdio(0);
	
	int N; cin >> N;
 
	V<vi> A(3, vi(N));
 
	for(int t = 0; t < 3; t++) {
		for(int i = 0; i < N; i++) {
			int x; cin >> x; --x; A[t][x] = N - 1 - i;
		}
	}
 
	vi ord(N); iota(begin(ord), end(ord), 0);
 
	V<vi> oc(N), C(8, vi(3));
 
	for(int i = 0; i < N; i++) {
		int mx = max({A[0][i], A[1][i], A[2][i]});
		oc[mx].pb(i);
	}
 
	vl ans(N), amt(3);
 
	for(int x = 0; x < N; x++) {
		for(auto& i : oc[x]) {
			// cout << x << " =====> " << i << endl;
			int msk = 0;
			for(int c = 0; c < 3; c++) if (A[c][i] == x) msk ^= (1 << c);
 
			for(int sur = 0; sur < 3; sur++) {
				ans[i] += C[msk][sur];
				amt[sur] += C[msk][sur];
			}
		}
 
		for(auto& i : oc[x]) {
			for(auto& j : oc[x]) if (i < j) {
				int best = 0;
				for(int sur = 0; sur < 3; sur++) {
					int bw = max(A[best][i], A[best][j]), bl = min(A[best][i], A[best][j]);
					int sw = max(A[sur][i], A[sur][j]), sl = min(A[sur][i], A[sur][j]);
 
					if (bw < sw) best = sur;
					if (bw == sw && bl < sl) best = sur;
				}
 
				// cout << i << " VS " << j << " => " << best << endl;
				amt[best]++;
				if (A[best][i] > A[best][j]) ans[i]++;
				else ans[j]++;
			}
 
			for(int m = 1; m < 8; m++) {
				int mx = 0; for(int b = 0; b < 3; b++) if ((m >> b) & 1) mx = max(mx, A[b][i]);
				
				int opt = 10; for(int b = 0; b < 3; b++) if ((m >> b) & 1) {
					if (mx == A[b][i]) opt = min(opt, b);
				}
 
				// cout << i << " " << m << " => " << opt << endl;
				C[m][opt]++;
			}
		}
	}
 
	for(auto& x : amt) cout << x << " ";
	cout << nl;
	for(auto& x : ans) cout << x << " ";
	cout << nl;
 
 
 
	exit(0-0);
}

