#include <bits/stdc++.h>
#define ll long long int

using namespace std;

const ll N=2005,inf=1e+18;
ll n,m,a[N][N],d=0,ans=-inf;
unordered_map <ll,ll> mp;
vector <ll> v;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>n>>m;
    for (ll i=1;i<=n;i++){
        a[i][0]=0;
        a[i][m+1]=0;
    }
    for (ll i=1;i<=m;i++){
        a[0][i]=0;
        a[n+1][i]=0;
    }
    for (ll i=1;i<=n;i++)
        for (ll j=1;j<=m;j++)
            cin>>a[i][j];
    for (ll i=1;i<=n;i++)
        for (ll j=1;j<=m;j++){
            ll x=a[i][j]+a[i-1][j]+a[i+1][j]+a[i][j-1]+a[i][j+1];
            if (mp[x]==0) v.push_back(x);
            mp[x]++;
        }
    for (ll i=0;i<v.size();i++)
        if (mp[v[i]]>d){
            d=mp[v[i]];
            ans=v[i];
        }
        else if (mp[v[i]]==d) ans=max(ans,v[i]);
    cout<<ans;
}

