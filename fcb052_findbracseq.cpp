#include <bits/stdc++.h>
#define int long long
using namespace std;
const int MOD = 1e9 + 7;
signed main() {
	string s; cin >> s;
	string newStr;
	for (int i = 0; i < s.size(); i++) {
		if (s[i] == '(' || s[i] == ')') {
			newStr.push_back(s[i]);
		}
	}
	int n = newStr.size();
	s = newStr;
	int ans = 0;
	stack<char> mystack;
	for (int i = 0; i < n; i++) {
		if (s[i] == '(') {
			mystack.push('(');
		}
		else {
			if (mystack.empty()) continue;
			mystack.pop();
			ans += 2;
		}
	}
	cout << ans;
	return 0;
}

