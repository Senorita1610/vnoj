#include <bits/stdc++.h>
using namespace std;
 
int n;
vector<int> ac, at, ca, ct, ta, tc;
 
void init(std::string a, std::string b) {
	n = a.size();
	ac.resize(n, 0);
	at.resize(n, 0);
	ca.resize(n, 0);
	ct.resize(n, 0);
	ta.resize(n, 0);
	tc.resize(n, 0);
	if (a[0]=='A'&&b[0]=='C') ac[0]++;
	if (a[0]=='A'&&b[0]=='T') at[0]++;
	if (a[0]=='C'&&b[0]=='A') ca[0]++;
	if (a[0]=='C'&&b[0]=='T') ct[0]++;
	if (a[0]=='T'&&b[0]=='A') ta[0]++;
	if (a[0]=='T'&&b[0]=='C') tc[0]++;
	for (int i = 1; i < n; i++) {
		ac[i] = ac[i-1];
		at[i] = at[i-1];
		ca[i] = ca[i-1];
		ct[i] = ct[i-1];
		ta[i] = ta[i-1];
		tc[i] = tc[i-1];
		if (a[i]=='A'&&b[i]=='C') ac[i]++;
		if (a[i]=='A'&&b[i]=='T') at[i]++;
		if (a[i]=='C'&&b[i]=='A') ca[i]++;
		if (a[i]=='C'&&b[i]=='T') ct[i]++;
		if (a[i]=='T'&&b[i]=='A') ta[i]++;
		if (a[i]=='T'&&b[i]=='C') tc[i]++;
	}
}
 
int calc (int a, int b, int c, int d, int e, int f) {
	int s = 0;
	s += min(a, c)+min(b, e)+min(d, f);
	int x = min(a, c), y = min(b, e), z = min(d, f);
	a -= x;
	c -= x;
	b -= y;
	e -= y;
	d -= z;
	f -= z;
	if (a == d && d == e && b == c && c == f) {
		return s+a*2+b*2;
	}
	else {
		return -1;
	}
}
 
int get_distance(int x, int y) {
	if (x == 0) return calc(ac[y], at[y], ca[y], ct[y], ta[y], tc[y]);
	return calc(ac[y]-ac[x-1], at[y]-at[x-1], ca[y]-ca[x-1], ct[y]-ct[x-1], ta[y]-ta[x-1], tc[y]-tc[x-1]);
}

