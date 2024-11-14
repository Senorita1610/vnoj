#include <cstdio> 
#include <cassert>
#include <vector>
#include <algorithm> 
 
#define X first
#define Y second
#define EB emplace_back
 
using namespace std;
 
typedef long long ll;
 
struct dot {
	ll x, y;
	dot() {}
	dot(ll x, ll y) : x(x), y(y) {}
	bool operator< (dot p) { return (p.x - x) * (-y) - (p.y - y) * (-x) > 0; }
	ll operator* (dot p) { return p.x * x + p.y * y; }
};
 
ll ccw(dot a, dot b, dot c) { return (b.x - a.x) * (c.y - a.y) - (b.y - a.y) * (c.x - a.x); }
 
const int LOG = 17; 
const int N = 1 << LOG;
 
dot D[N][2], INV[N];
int L[N], R[N], ANS[N];
vector<int> Q[2 * N], I[N]; 
vector<dot> CH, CIR;
 
int query(const dot &d, int lo, int hi) {
	while(hi - lo > 1) {
		int mi = (lo + hi) / 2;
		if(CH[mi] * d < CH[mi + 1] * d) hi = mi;
		else lo = mi;
	}
	return CH[lo] * d < CH[hi] * d ? lo : hi;
}
 
void fake() {
	for(dot d : CIR) {
		while(CH.size() > 1 && ccw(end(CH)[-2], end(CH)[-1], d) > 0) CH.pop_back(); 
		CH.EB(d); 
	}
	for(int i : Q[1]) 
		if(ccw(D[i][1], D[i][0], CH[query(INV[i], 0, (int) CH.size() - 1)]) > 0) ANS[i] = 1;
}
 
void divcon(int lo, int hi, int x = 1) {
	if(lo >= hi || Q[x].empty()) return;
	if(lo + 1 == hi) {
		for(int i : Q[x]) ANS[i] |= ccw(D[i][1], D[i][0], CIR[lo]) > 0;
		return;
	}
	int mi = (lo + hi) / 2;
	for(int i : Q[x]) {
		if(R[i] < mi) Q[2 * x].EB(i); 
		else if(L[i] >= mi) Q[2 * x + 1].EB(i); 
		else I[L[i]].EB(i), I[R[i]].EB(i); 
	}
	CH.clear();	
	for(int i = mi; i < hi; ++i) {
		dot d = CIR[i]; 
		while(CH.size() > 1 && ccw(end(CH)[-2], end(CH)[-1], d) > 0) CH.pop_back(); 
		CH.EB(d); 
		for(int j : I[i])
			if(ccw(D[j][1], D[j][0], CH[query(INV[j], 0, (int) CH.size() - 1)]) > 0) ANS[j] = 1;
	}
	CH.clear();
	for(int i = mi - 1; i >= lo; --i) {
		dot d = CIR[i]; 
		while(CH.size() > 1 && ccw(end(CH)[-2], end(CH)[-1], d) < 0) CH.pop_back(); 
		CH.EB(d); 
		for(int j : I[i])
			if(ccw(D[j][1], D[j][0], CH[query(INV[j], 0, (int) CH.size() - 1)]) > 0) ANS[j] = 1;
	}
	for(int i = lo; i < hi; ++i) I[i].clear();
	divcon(lo, mi, 2 * x); 
	divcon(mi, hi, 2 * x + 1);
}
 
int search(const dot &d) {
	int lo = -1, hi = (int) CIR.size();
	while(hi - lo > 1) {
		int mi = (lo + hi) / 2;
		if(CIR[mi] < d) lo = mi;
		else hi = mi;
	}
	return hi;
}
 
int main() {
	int n, m;
	scanf("%d%d", &n, &m); 
	for(int i = 0; i < n; ++i) {
		int x, y;
		scanf("%d%d", &x, &y); 
		CIR.EB(dot(x, y)); 
	}
	sort(CIR.begin(), CIR.end()); 
//	for(int i = 0; i < n; ++i) printf("%d %d\n", (int) CIR[i].x, (int) CIR[i].y);
	for(int i = 0; i < m; ++i) {
		int x, y, _x, _y;
		scanf("%d%d%d%d", &x, &y, &_x, &_y); 
		D[i][0] = dot(x, y); 
		D[i][1] = dot(_x, _y); 
		INV[i] = dot(- (D[i][1].y - D[i][0].y), D[i][1].x - D[i][0].x);
 
		L[i] = search(D[i][1]); 
		R[i] = search(D[i][0]) - 1;
//		printf("%d: %d %d\n", i, L[i], R[i]);
		if(L[i] <= R[i]) Q[1].EB(i);
	}
	divcon(0, n);
	for(int i = 0; i < m; ++i) printf("%c\n", ANS[i] ? 'Y' : 'N');
	return 0;
}

