#include <bits/stdc++.h>
#define ll long long int

using namespace std;

const ll N=100005,MOD=1e9+7;
multiset <ll> a[N];
ll n,m,x,y,d,s[N],ans[N];
unordered_map <ll,ll> mp,mp1;
void Topo(ll i){
    mp1[i]=1;
    for (auto x : a[i])
        if (mp1[x]==0) Topo(x);
    s[d]=i;
    d--;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>n>>m;
    d=n;
    for (ll i=1;i<=m;i++){
        cin>>x>>y;
        a[x].insert(y);
        mp[y]=1;
    }
    for (ll i=1;i<=n;i++)
        if (mp[i]==0) Topo(i);
    ans[1]=1;
    for (ll i=1;i<n;i++)
        for (auto j : a[s[i]]) ans[j]=(ans[j]+ans[s[i]])%MOD;
    cout<<ans[n];
}

