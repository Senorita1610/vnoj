#include<bits/stdc++.h>
using namespace std;
string s;
vector<char>s1,s2;
int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);	
	cin>>s;
	for (auto i:s) {
		if (i=='<') {
			if (!s1.empty()) {
				s2.push_back(s1.back());
				s1.pop_back();
			} 
		} else if (i=='>') {
			if (!s2.empty()) {
				s1.push_back(s2.back());
				s2.pop_back();
			}
		} else if (i=='-') {
			if (!s1.empty()) s1.pop_back();
		} else s1.push_back(i);
	}
	while (!s2.empty()) {
		s1.push_back(s2.back());
		s2.pop_back();
	}
	for (auto c:s1) cout<<c;
}

