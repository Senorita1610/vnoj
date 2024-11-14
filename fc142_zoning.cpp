#include <bits/stdc++.h>
#define ll long long int

using namespace std;

const ll N=1000005;
ll t,n,x,a[N];
void Solve(){
    cin>>n>>x;
    unordered_map <ll,ll> mp;
    ll ans=0;
    a[0]=0,mp[0]=1;
    for (ll i=1;i<=n;i++){
        cin>>a[i];
        a[i]+=a[i-1];
        ans+=mp[a[i]-x];
        mp[a[i]]++;
    }
    (ans==0) ? cout<<"HUHU"<<endl : cout<<ans<<endl;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>t;
    while (t--) Solve();
}

