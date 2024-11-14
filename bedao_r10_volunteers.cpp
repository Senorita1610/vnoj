#include<bits/stdc++.h>
using namespace std;
int n,m;
multiset<int>s;
int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin>>n>>m;
    for (int i=1;i<=n;i++) {
    	int x;
    	cin>>x;
    	s.insert(x);
    }	
    for (int i=1;i<=m;i++) {
    	int x;
    	cin>>x;
    	auto it=s.upper_bound(x);
    	if (it!=s.begin()) {
    		it--;
    		s.erase(it);
    	}
    }
    if (s.empty()) cout<<-1;
    else cout<<(*s.rbegin());
}

