#include <bits/stdc++.h>
using namespace std;

#define ll long long 
#define ff(i, a, b) for(int i = a; i <= b; i++)
#define fo(i, a, b) for(int i = a; i < b; i++)
#define fod(i, a, b) for(int i = a; i >= b; i--)

const int INF = 1e9, N = 150;
const ll INFL = 1e18;

typedef pair <int, int> ii;
typedef vector <int> vi;
typedef vector <ii> vii;

double f[N][N][N];
double P[N][N][N];
int n, w[N], b[N];
double A[N][N];

void prep() {
	fo(W, 0, N) ff(i, 0, W) {
		P[W][0][i] = 1.0;
		fo(B, 1, N) P[W][B][i] = P[W][B - 1][i] * (double) (W - i + B) / (W + B);
	} 
}

void process() {
	prep();
	fo(W, 0, N) f[W][0][W] = 1.0;
	ff(B, 1, 100) ff(W, 0, 100) fo(i, 0, N) {
		fo(j, 0, N) {
			if (i >= j + 1 && W >= i - 1) {
				f[W][B][i] += P[W][B][i - 1] * P[B][W - i + 1][1] * f[W - i + 1][B - 1][j];
			} 
			else if(i < j && W >= i) {
				f[W][B][i] += P[W][B][i] * P[B][W - i][1] * f[W - i][B - 1][j];
			}
		}
	}
}

void solve() {
	cin >> n; ff(i, 1, n) cin >> b[i]; ff(i, 1, n) cin >> w[i];
	ff(i, 0, n) fo(j, 0, N) A[i][j] = 0.0; A[0][0] = 1.0;
	fo(i, 0, n) fo(j, 0, N) {
		fo(k, 0, N) A[i + 1][j ^ k] += A[i][j] * f[w[i + 1]][b[i + 1]][k];
	}
	cout << setprecision(6) << fixed << 1.0 - A[n][0] << "\n";
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	process();
	int t; cin >> t;
	while(t--) solve();
}

