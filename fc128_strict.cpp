#include <bits/stdc++.h>
#define ll long long int

using namespace std;

const ll MOD=1e9+7;
unordered_map <ll,ll> mp;
vector <ll> v;
ll n,a,ans=1;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>n;
    for (ll i=1;i<=n;i++){
        cin>>a;
        if (mp[a]==0) v.push_back(a);
        mp[a]++;
    }
    for (auto x : v)
        ans=(ans*(mp[x]+1))%MOD;
    cout<<ans;
}

