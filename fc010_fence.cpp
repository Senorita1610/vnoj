#include <bits/stdc++.h>
#define X first
#define Y second
#define pb push_back
#define pii pair<int, int>
typedef long long ll;
using namespace std;
 
const int MOD = 1e9 + 7;
const ll INF = 1e18;
const int OFF = (1 << 20);
 
int n, m;
pii holes[105];
pii trees[105];
int dist[105][105];
vector<pii> ljuska;
vector<pii> drva;
 
int ccw(pii a, pii b, pii c) {
	return a.X * (b.Y - c.Y) + b.X * (c.Y - a.Y) + c.X * (a.Y - b.Y);
}
 
int main () {
 
	cin >> n >> m;
	for (int i = 0; i < n; i++) cin >> holes[i].X >> holes[i].Y;
	for (int i = 0; i < m; i++) cin >> trees[i].X >> trees[i].Y;
	
	
	sort(holes, holes + n);
	ljuska.push_back(holes[0]);
	ljuska.push_back(holes[1]);
	for (int i = 2; i < n; i++) {
		while (ljuska.size() > 1 && ccw(ljuska[(int)ljuska.size()-2], ljuska.back(), holes[i]) >= 0) ljuska.pop_back();
		ljuska.push_back(holes[i]);
	}
	
	int kol = ljuska.size();
	for (int i = n-2; i >= 0; i--) {
		while (ljuska.size() > kol && ccw(ljuska[(int)ljuska.size()-2], ljuska.back(), holes[i]) >= 0) ljuska.pop_back();
		if (i > 0) ljuska.push_back(holes[i]);
	}
	
	for (int i = 0; i < m; i++) {
		int da = 1;
		if (ccw(ljuska.back(), ljuska[0], trees[i]) >= 0) da = 0;
		
		for (int j = 1; j < ljuska.size(); j++) {
			if (ccw(ljuska[j-1], ljuska[j], trees[i]) >= 0) {
				da = 0;
				break;
			}
		}
		
		if (da) drva.push_back(trees[i]);
	}
	
	if (drva.size() == 0) {
		cout << m*111;
		return 0;
	}
	
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			int da = 1;
			for (int k = 0; k < drva.size(); k++) {
				if (ccw(holes[i], holes[j], drva[k]) >= 0) {
					da = 0;
					break;
				}
			}
			
			if (i != j && da) {
				dist[i][j] = 1;
			}
			else {
				dist[i][j] = 1e6;
			}
		}
	}
	
	for (int k = 0; k < n; k++) {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				dist[i][j] = min(dist[i][j], dist[i][k]+dist[k][j]);
			}
		}
	}
	
	int mini = 1e9;
	for (int i = 0; i < n; i++) mini = min(mini, dist[i][i]);
	
	cout << 111*(m-drva.size())+mini*20;
 
	return 0;
}

