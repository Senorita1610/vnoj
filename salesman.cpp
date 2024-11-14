#include <bits/stdc++.h>
using namespace std;
constexpr int M=500002;
 
struct pii {
	int x, v;
	bool operator<(pii b) const { return x<b.x; }
};
int main() {
	ios::sync_with_stdio(0);cin.tie(0);
	int N, L, R, st;
	cin>>N>>L>>R>>st;
	vector<pii> A[M];
	for(int i=0; i<N; i++) {
		int t, x, v;
		cin>>t>>x>>v;
		A[t].push_back({x, v});
	}
	auto set=[&](int* T, int i, int x) {
		for(; i<M; i+=i&-i) T[i]=max(T[i], x);
	};
	auto qry=[&](int* T, int i) {
		int x=-2e9;
		for(; i; i-=i&-i) x=max(x, T[i]);
		return x;
	};
	int T1[M], T2[M];
	fill(T1, T1+M, -2e9);
	fill(T2, T2+M, -2e9);
	set(T1, st, st*R);
	set(T2, M-st, -st*L);
	for(auto&X:A) if(int n=X.size()) {
		sort(X.begin(), X.end());
		int D[n], E[n];
		for(int i=0, m=-2e9; i<n; i++) {
			auto[x,v]=X[i];
			D[i]=max(qry(T1, x)-x*R, qry(T2, M-x)+x*L)+v;
			E[i]=m=max(m+v, D[i]+x*R);
		}
		for(int i=n-1, m=-2e9; i>=0; i--) {
			auto[x,v]=X[i];
			m=max(m+v, D[i]-x*L);
			int t=max(m+x*L, E[i]-x*R);
			set(T1, x, t+x*R);
			set(T2, M-x, t-x*L);
		}
	}
	cout<<max(qry(T1, st)-st*R, qry(T2, M-st)+st*L)<<'\n';
}

