#include<bits/stdc++.h>
using namespace std;
#pragma GCC optimize("unroll-loops,02,no-stack-protector")
#pragma GCC optimize("O3")
#pragma GCC optimize("O1")
#pragma GCC optimize("O1")
#pragma GCC target("avx2")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("avx")
#pragma GCC optimize(3)
#pragma GCC optimize("Ofast")
#pragma GCC optimize("inline")
#pragma GCC optimize("-fgcse")
#pragma GCC optimize("-fgcse-lm")
#pragma GCC optimize("-fipa-sra")
#pragma GCC optimize("-ftree-pre")
#pragma GCC optimize("-ftree-vrp")
#pragma GCC optimize("-fpeephole2")
#pragma GCC optimize("-ffast-math")
#pragma GCC optimize("-fsched-spec")
#pragma GCC optimize("-falign-jumps")
#pragma GCC optimize("-falign-loops")
#pragma GCC optimize("-falign-labels")
#pragma GCC optimize("-fdevirtualize")
#pragma GCC optimize("-fcaller-saves")
#pragma GCC optimize("-fcrossjumping")
#pragma GCC optimize("-fthread-jumps")
#pragma GCC optimize("-freorder-blocks")
#pragma GCC optimize("-fschedule-insns")
#pragma GCC optimize("inline-functions")
#pragma GCC optimize("-ftree-tail-merge")
#pragma GCC optimize("-fschedule-insns2")
#pragma GCC optimize("-fstrict-aliasing")
#pragma GCC optimize("-falign-functions")
#pragma GCC optimize("-fcse-follow-jumps")
#pragma GCC optimize("-fsched-interblock")
#pragma GCC optimize("-fpartial-inlining")
#pragma GCC optimize("no-stack-protector")
#pragma GCC optimize("-freorder-functions")
#pragma GCC optimize("-findirect-inlining")
#pragma GCC optimize("-fhoist-adjacent-loads")
#pragma GCC optimize("-frerun-cse-after-loop")
#pragma GCC optimize("inline-small-functions")
#pragma GCC optimize("-finline-small-functions")
#pragma GCC optimize("-ftree-switch-conversion")
#pragma GCC optimize("-foptimize-sibling-calls")
#pragma GCC optimize("-fexpensive-optimizations")
#pragma GCC optimize("inline-functions-called-once")
#pragma GCC optimize("-fdelete-null-pointer-checks")
#pragma GCC target("avx,avx2,sse,sse2,sse3,ssse3,sse4,sse4.1,sse4.2,mmx,abm")

static struct FastInput {
	static constexpr int BUF_SIZE = 1 << 20;
	char buf[BUF_SIZE];
	size_t chars_read = 0;
	size_t buf_pos = 0;
	FILE *in = stdin;
	char cur = 0;

	inline char get_char() {
		if (buf_pos >= chars_read) {
			chars_read = fread(buf, 1, BUF_SIZE, in);
			buf_pos = 0;
			buf[0] = (chars_read == 0 ? -1 : buf[0]);
		}
		return cur = buf[buf_pos++];
	}

	inline void tie(int) {}

	inline explicit operator bool() {
		return cur != -1;
	}

	inline static bool is_blank(char c) {
		return c <= ' ';
	}

	inline bool skip_blanks() {
		while (is_blank(cur) && cur != -1) {
			get_char();
		}
		return cur != -1;
	}

	inline FastInput &operator>>(char &c) {
		skip_blanks();
		c = cur;
		return *this;
	}

	inline FastInput &operator>>(string &s) {
		if (skip_blanks()) {
			s.clear();
			do {
				s += cur;
			} while (!is_blank(get_char()));
		}
		return *this;
	}

	template <typename T>
	inline FastInput &read_integer(T &n) {
		// unsafe, doesn't check that characters are actually digits
		n = 0;
		if (skip_blanks()) {
			int sign = +1;
			if (cur == '-') {
				sign = -1;
				get_char();
			}
			do {
				n += n + (n << 3) + cur - '0';
			} while (!is_blank(get_char()));
			n *= sign;
		}
		return *this;
	}

	template <typename T>
	inline typename enable_if<is_integral<T>::value, FastInput &>::type operator>>(T &n) {
		return read_integer(n);
	}

#if !defined(_WIN32) | defined(_WIN64)
	inline FastInput &operator>>(__int128 &n) {
		return read_integer(n);
	}
#endif

	template <typename T>
	inline typename enable_if<is_floating_point<T>::value, FastInput &>::type operator>>(T &n) {
		// not sure if really fast, for compatibility only
		n = 0;
		if (skip_blanks()) {
			string s;
			(*this) >> s;
			sscanf(s.c_str(), "%lf", &n);
		}
		return *this;
	}
} fast_input;

static struct FastOutput {
	static constexpr int BUF_SIZE = 1 << 20;
	char buf[BUF_SIZE];
	size_t buf_pos = 0;
	static constexpr int TMP_SIZE = 1 << 20;
	char tmp[TMP_SIZE];
	FILE *out = stdout;

	inline void put_char(char c) {
		buf[buf_pos++] = c;
		if (buf_pos == BUF_SIZE) {
			fwrite(buf, 1, buf_pos, out);
			buf_pos = 0;
		}
	}

	~FastOutput() {
		fwrite(buf, 1, buf_pos, out);
	}

	inline FastOutput &operator<<(char c) {
		put_char(c);
		return *this;
	}

	inline FastOutput &operator<<(const char *s) {
		while (*s) {
			put_char(*s++);
		}
		return *this;
	}

	inline FastOutput &operator<<(const string &s) {
		for (int i = 0; i < (int)s.size(); i++) {
			put_char(s[i]);
		}
		return *this;
	}

	template <typename T>
	inline char *integer_to_string(T n) {
		// beware of TMP_SIZE
		char *p = tmp + TMP_SIZE - 1;
		if (n == 0) {
			*--p = '0';
		} else {
			bool is_negative = false;
			if (n < 0) {
				is_negative = true;
				n = -n;
			}
			while (n > 0) {
				*--p = (char)('0' + n % 10);
				n /= 10;
			}
			if (is_negative) {
				*--p = '-';
			}
		}
		return p;
	}

	template <typename T>
	inline typename enable_if<is_integral<T>::value, char *>::type stringify(T n) {
		return integer_to_string(n);
	}

#if !defined(_WIN32) || defined(_WIN64)
	inline char *stringify(__int128 n) {
		return integer_to_string(n);
	}
#endif

	template <typename T>
	inline typename enable_if<is_floating_point<T>::value, char *>::type stringify(T n) {
		sprintf(tmp, "%.17f", n);
		return tmp;
	}

	template <typename T>
	inline FastOutput &operator<<(const T &n) {
		auto p = stringify(n);
		for (; *p != 0; p++) {
			put_char(*p);
		}
		return *this;
	}
} fast_output;

#define cin fast_input
#define cout fast_output
#define FOR(i, a, b) for(int i=(a), _b=(b); i<_b; ++i)
#define fi first
#define se second
#define pb push_back
#define ll long long
#define all(a) a.begin(),a.end()
typedef pair<int, int> pii;
const int N = 9 + 1e7;
const int INF = 1e9;

int n, x, a[N];

int32_t main() {
#define TASKNAME "bedao_g03_bonpair"
	ios_base::sync_with_stdio (0);
	cin.tie (0);
	if ( fopen( TASKNAME".inp", "r" ) ) {
		freopen (TASKNAME".inp", "r", stdin);
		freopen (TASKNAME".out", "w", stdout);
	}
	cin >> n >> x;
	for(int i = 0; i < n; i++) cin >> a[i];
	ll res = 0;
	for(int i = 0; i < n; i++) {
		auto pos = upper_bound(a + i + 1, a + n, x - a[i]) - a - 1;
		//cout << pos << '\n';
		//if(a[i] + a[pos] > x) pos--; 
		res += (pos - i);
	}
	cout << res;
	return 0;
}

