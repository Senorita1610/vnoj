#include <bits/stdc++.h>
using namespace std;
 
#define fast ios::sync_with_stdio(0);cin.tie(0);
#define s second
#define f first
typedef long long ll;
const ll MOD = 998244353;
const ll LOGN = 18; 
const ll INF = 1e15;
const ll MAXN = 1e6 + 5;
	
int ans[MAXN]; 
int main() {
	fast
	int N, M;
	cin >> N >> M;
 
	vector<int> A, B;
	for (int i = 0; i < N; i++)
		A.push_back(i);
	for (int i = M + N - 1; i >= M; i--)
		B.push_back(i);
 
	while (A.size()) {
		vector<int> right;
		while ((A.back() & B.back()) != A.back()) {
			right.push_back(B.back());
			B.pop_back();
		}
 
		// right azalan sekilde gidiyor.
		right.push_back(B.back());
		B.pop_back();
 
		while (right.size()) {
			ans[A.back()] = right.back();
			A.pop_back();
			right.pop_back();
		}
	}
 
	for (int i = 0; i < N; i++)
		cout << i << " " << ans[i] << "\n";
}

