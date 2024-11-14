#include <bits/stdc++.h>
using namespace std;
void solve() {
    int n, s;
    cin>>n>>s;
    vector<int>w(n),v(n);
    for(auto &i:w) cin>>i;
    for(auto &i:v) cin>>i;
    long long ans=0;
    for(int i=0;i<n;i++){
        if(s>=w[i]) ans+=v[i];
    }
    cout<<ans<<'\n';
}
int main() {
    cin.tie(0)->sync_with_stdio(0);
    int T; cin>>T;
    while(T--) solve();
}

