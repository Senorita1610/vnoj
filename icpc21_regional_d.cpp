#include<bits/stdc++.h>
using namespace std;
int n,t;
set<int>s,ex;
int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);	
    cin>>n;
    while (n--) {
    	cin>>t;
    	if (!ex.count(t)) {
	    	if (s.count(t)) {
	    		s.erase(s.find(t));
	    		ex.insert(t);
	    	} else {
	    		s.insert(t);
	    	}
    	}
    	if (!s.empty()) cout<<(*s.begin())<<'\n';
    	else cout<<-1<<'\n';
    }
}

