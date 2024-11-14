#include <vector>
 
using namespace std;
 
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
 
const int N = 2000;
 
int min(int a, int b) { return a < b ? a : b; }
int max(int a, int b) { return a > b ? a : b; }
 
int ll[N][N], uu[N][N], dd[N][N], dp[N][N], ii[N];
 
int biggest_stadium(int n, vvi aa) {
	for (int i = 0; i < n; i++)
		for (int j = 0, l = 0; j < n; j++)
			if (aa[i][j])
				l = j + 1;
			else
				ll[i][j] = l;
	for (int j = 0; j < n; j++)
		ii[j] = 0;
	for (int i = 0; i < n; i++)
		for (int j = 0, u = 0; j < n; j++)
			if (aa[i][j])
				ii[j] = i + 1, u = 0;
			else
				uu[i][j] = u = max(u, ii[j]);
	for (int j = 0; j < n; j++)
		ii[j] = n - 1;
	for (int i = n - 1; i >= 0; i--)
		for (int j = 0, d = n - 1; j < n; j++)
			if (aa[i][j])
				ii[j] = i - 1, d = n - 1;
			else
				dd[i][j] = d = min(d, ii[j]);
	int ans = 0;
	for (int l = n - 1; l >= 0; l--)
		for (int i = 0; i < n; i++)
			if (!aa[i][l] && ll[i][l] == l)
				for (int j = l; j < n && !aa[i][j]; j++) {
					int u = uu[i][j], d = dd[i][j];
					if (j == l)
						dp[i][j] = d - u + 1;
					else {
						dp[i][j] = dp[i][j - 1] + d - u + 1;
						if (u > 0 && !aa[u - 1][j])
							dp[i][j] = max(dp[i][j], dp[u - 1][j] + (d - u + 1) * (ll[u - 1][j] - ll[i][j]));
						if (d + 1 < n && !aa[d + 1][j])
							dp[i][j] = max(dp[i][j], dp[d + 1][j] + (d - u + 1) * (ll[d + 1][j] - ll[i][j]));
					}
					ans = max(ans, dp[i][j]);
				}
	return ans;
}

