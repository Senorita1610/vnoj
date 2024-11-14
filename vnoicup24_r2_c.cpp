#include<bits/stdc++.h>

using namespace std;
template<class integer>
inline integer to_int(const string& s, size_t* idx = 0, int base = 10) {
    size_t n = s.size(), i = idx ? *idx : 0; bool sign = false; integer x = 0;
    if (s[i] == '-')
        ++i, sign = true;
    function<int(char)> char_to_digit = [&](char c) {
        static const int d[] = {'a'-10,'0'}; 
        return tolower(c)-d[isdigit(c)]; };
    while (i < n)
        x *= base, x += char_to_digit(s[i++]);
    if (idx)
        *idx = i; 
    return sign ? -x : x; }
 
template<class integer>
inline string to_string(integer x, int base = 10) {
    bool sign = false; string s;
    if (x < 0)
        x = -x, sign = true;
    function<char(int)> digit_to_char = [](int d) {
        static const char c[] = {'a'-10,'0'};
        return c[d < 10]+d; };
    do 
        s += digit_to_char(x%base), x /= base;
    while (x > 0); 
    if (sign)
        s += '-';
    reverse(s.begin(),s.end());
    return s; }
 
template<class integer>
inline istream& read(istream& is, integer& x) {
    string s; is >> s, x = to_int<integer>(s); return is; }
 
template<class integer>
inline ostream& write(ostream& os, integer x) { return os << to_string(x); }
 
using  lll =   signed __int128; 
using ulll = unsigned __int128;
 
inline istream& operator>>(istream& is,  lll &x) { return  read(is,x); }
inline istream& operator>>(istream& is, ulll &x) { return  read(is,x); }
inline ostream& operator<<(ostream& os,  lll  x) { return write(os,x); }
inline ostream& operator<<(ostream& os, ulll  x) { return write(os,x); }
#define int __int128

const int maxN = 3e5+5;
typedef pair<int,int> ii;
int n, pref[maxN];
ii a[maxN];
int calc(int x){
	int pos = upper_bound(a+1,a+n+1,ii{x,1e18})-a-1;
	int sum1 = a[pos].second*x-pref[pos];
	int sum2 = pref[n]-pref[pos]-x*(a[n].second-a[pos].second);
	return sum1+sum2;
}

int abs(int x){
	if (x>0) return x;
	else return -x;
}

void solve(){
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> a[i].first;
	for (int i = 1; i <= n; i++) cin >> a[i].second;
	sort(a+1,a+n+1);
	for (int i = 1; i <= n; i++) pref[i] = pref[i-1] + a[i].second*a[i].first;
	for (int i = 1; i <= n; i++) a[i].second += a[i-1].second;
	int res = 1e18, x = -1e9;
	a[n+1].first = 1e9;
	a[0].first = -1e9;
	
	for (int i = 0; i <= n+1; i++){
		int y = a[i].first;
		int tmp = calc(y);
		if (ii{tmp,abs(y)}<ii{res,abs(x)}){
			res = tmp;
			x = y;
		}
	}
	if (abs(x)==1e9){
		cout << "-inf" << "\n";
	} else 
	cout << res << "\n";
}

main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int t; cin >> t;
	while (t--)
	solve();
}

