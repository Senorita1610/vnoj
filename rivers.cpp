#include <bits/stdc++.h>
using namespace std;

const int maxn = 105;

struct edge
{
	int to, dist;
};

vector<vector<edge> > graph;

int c[maxn], depth[maxn];
long long f[maxn][maxn][maxn], g[maxn][maxn][maxn];
deque<int> st;
int n, k;

void dfs(int p)
{
	st.push_back(p);
	for (vector<edge>::iterator i = graph[p].begin(); i != graph[p].end(); i++)
	{
		depth[i->to] += depth[p] + i->dist;
		dfs(i->to);
		for (deque<int>::iterator j = st.begin(); j != st.end(); j++)
			for (int l = k; ~l; l--)
			{
				f[p][*j][l] += f[i->to][*j][0];
				g[p][*j][l] += f[i->to][p][0];
				for (int x = 0; x <= l; x++)
				{
					f[p][*j][l] = min(f[p][*j][l], f[p][*j][l - x] + f[i->to][*j][x]);
					g[p][*j][l] = min(g[p][*j][l], g[p][*j][l - x] + f[i->to][p][x]);
				}
			}
	}
	for (deque<int>::iterator j = st.begin(); j != st.end(); j++)
	{
		f[p][*j][0] += c[p] * (depth[p] - depth[*j]);
		for (int l = 1; l <= k; l++)
			f[p][*j][l] = min(f[p][*j][l] + c[p] * (depth[p] - depth[*j]), g[p][*j][l - 1]);
	}
	st.pop_back();
	return;
}

int main()
{
	scanf("%d%d", &n, &k);
	graph.resize(n + 1);
	for (int i = 1; i <= n; i++)
	{
		int fa, dist;
		scanf("%d%d%d", c + i, &fa, &dist);
		graph[fa].push_back((edge){i, dist});
	}
	dfs(0);
	printf("%d\n", f[0][0][k]);
	return 0;
}

