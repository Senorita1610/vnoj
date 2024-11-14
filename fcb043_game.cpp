#include<bits/stdc++.h>
using namespace std;
int n;
string s;
int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);	
	cin>>n>>s;
	s=' '+s;
	int m=(n-11)/2,pos,last;
	for (int i=1;i<=n;i++) {
		if (s[i]=='8'&&m>0) {
			m--;
		} else if (s[i]=='8'&&m==0) {
			last=i;
			m--;
			break;
		}
		
	}
	if (m>=0) {
		cout<<"NO";
	} else {
		m=(n-11)/2;
		if (last-1-m<=m) cout<<"YES";
		else cout<<"NO";
	}
}

