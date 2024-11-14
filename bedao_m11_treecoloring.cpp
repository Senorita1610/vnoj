#include <bits/stdc++.h>
#define ll long long int

using namespace std;

const ll N=100005;
ll n,x,y,z,mp[N]={};
vector <pair<ll,ll>> v[N];
void Try(ll i){
    for (auto j : v[i])
        if (mp[j.first]==-1){
            (j.second%2==0) ? mp[j.first]=mp[i] : mp[j.first]=(mp[i]+1)%2;
            Try(j.first);
        }
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>n;
    for (ll i=1;i<=n;i++) mp[i]=-1;
    for (ll i=1;i<n;i++){
        cin>>x>>y>>z;
        v[x].emplace_back(y,z);
        v[y].emplace_back(x,z);
    }
    mp[1]=1;
    Try(1);
    for (ll i=1;i<=n;i++) cout<<mp[i]<<" ";
}

