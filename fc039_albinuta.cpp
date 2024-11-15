#include <bits/stdc++.h>
using namespace std;

int gcd(int a, int b)
{
	if(!b)
		return a;
	return gcd(b, a % b);
}

int cmmmc(int a, int b)
{
	return (a * b) / gcd(a, b);
}
	
int main() {
	int n, q;
	cin >> n >> q;
	vector<vector<int>> adj(n + 1);
	int cm = 1;
	for(int i = 1;i <= n;++i)
	{
		int l;
		cin >> l;
		cm = cmmmc(cm, l);
		for(int j = 0;j < l;++j)
		{
			int nod;
			cin >> nod;
			adj[i].push_back(nod);
		}
	}
	int seen[n + 1][cm];
	vector<int> v;
	unordered_map<int, vector<int>> mp;
	int ans[q], tmax = 0;
	memset(seen, -1, sizeof(seen));
	
	for(int i = 0;i < q;++i)
	{
		int t;
	
		cin >> t;
		mp[t].push_back(i);
		tmax = max(tmax, t);
	}
	int cur = 1, index = -1, i;
	for(i = 1;i <= tmax;++i)
	{
		int l = adj[cur].size();
		int r = (i - 1) % cm;
			
		if(seen[cur][r] != -1)
		{
			index = seen[cur][r];
			break;
		}
		v.push_back(cur);
		if(mp.find(i) != mp.end())
		{
			vector<int>& tmp = mp[i];
			for(size_t j = 0;j < tmp.size();++j)
				ans[tmp[j]] = cur;
		}
		int nxt = adj[cur][(i - 1) % l];
		seen[cur][r] = v.size() - 1;
		cur = nxt;
	}
	int cycle = v.size() - index;
	for(auto it: mp)
		if(it.first >= i)
		{
			vector<int>& tmp = it.second;
			for(size_t j = 0;j < tmp.size();++j)
				ans[tmp[j]] = v[index + ((it.first - i) % cycle)];
		}
	for(int i = 0;i < q;++i)
		cout << ans[i] << "\n";
}
