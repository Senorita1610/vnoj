#include <bits/stdc++.h>
#define ll long long int

using namespace std;

const ll N=200005;
ll n,a[N],ans=0;
unordered_map <ll,ll> mp;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>n;
    for (ll i=1;i<=n;i++){
        cin>>a[i];
        ans+=mp[a[i]];
        mp[a[i]]++;
    }
    for (ll i=1;i<=n;i++) cout<<ans-mp[a[i]]+1<<endl;
}

