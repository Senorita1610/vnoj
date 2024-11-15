#include <bits/stdc++.h>
#define ll long long int

using namespace std;

ll n,m=1e+18,a;
unordered_map <ll,ll> mp;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>n;
    for (ll i=1;i<=n;i++){
        cin>>a;
        if (mp[a]!=0) m=min(m,i-mp[a]);
        mp[a]=i;
    }
    if (m==1e+18) m=-1;
    cout<<m;
    return 0;
}

