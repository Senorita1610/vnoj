#include<bits/stdc++.h>
using namespace std;
int t;
string s;
int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);	
	cin>>t;
	while (t--) {
		cin>>s;
		int n=s.size();
		if (n==1) {
			cout<<-1<<'\n';
			continue;
		}
		bool flag=false;
		s=' '+s;
		for (int i=1;i<n;i++) {
			if (s[i]==s[i+1]) {
				flag=true;
				break;
			}
		}
		for (int i=2;i<n;i++) {
			if (s[i-1]==s[i+1]) {
				flag=true;
				break;
			}
		}
		if (flag) cout<<0<<'\n';
		else cout<<1<<'\n';
	}
}

