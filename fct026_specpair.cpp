#include <bits/stdc++.h>
#define ll long long int

using namespace std;

const ll N=200005;
vector <ll> v;
ll n,ans=0,a[N];
unordered_map <ll,ll> mp;
void Build(){
    for (ll i=1;i<=9;i++){
        ll x=0;
        for (ll j=1;j<=6;j++){
            x=x*10+i;
            v.push_back(x);
        }
    }
    v.push_back(1111111);
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>n;
    Build();
    for (ll i=1;i<=n;i++){
        cin>>a[i];
        mp[a[i]]++;
    }
    sort(a+1,a+n+1);
    for (ll i=0;i<v.size();i++)
        for (ll j=1;j<=n;j++){
            if (a[j]>=v[i]) break;
            ans+=mp[v[i]-a[j]];
            if (a[j]*2==v[i]) ans--;
        }
    cout<<ans/2;
}

