#include<bits/stdc++.h>
using namespace std;
int n;
long long res;
map<int,long long>mp;
int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin>>n;
    for (int t,i=1;i<=n;i++) {
    	cin>>t;
    	mp[t]++;
    }
    for (auto i=mp.begin();i!=mp.end();i++) res+=i->second*(i->second-1)/2;
    cout<<res;
}

