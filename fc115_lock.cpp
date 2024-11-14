#include<bits/stdc++.h>
using namespace std;
int n,cnt;
string s;
bool used[10];
int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);	
    cin>>n>>s;
    s=' '+s;
    for (int i=1;i<=n;i++) {
    	if (s[i]==s[i-1]) {
    		cout<<0;
    		return 0;
    	}
    	if (!used[s[i]-'0']) {
    		used[s[i]-'0']=true;
    		cnt++;
    	}
    }
    if (cnt>=5) cout<<1;
    else cout<<0;
}

