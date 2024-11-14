#include <bits/stdc++.h>
#define ll long long int

using namespace std;

const ll N=200000;
ll n,a,x[N+5];
vector <pair<ll,ll>> v;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>n;
    for (ll i=1;i<=n;i++){
        cin>>a;
        v.emplace_back(a,i);
    }
    sort(v.begin(),v.end());
    for (ll i=0;i<v.size();i++)
        (i<n/2) ? x[v[i].second]=v[n/2].first : x[v[i].second]=v[n/2-1].first;
    for (ll i=1;i<=n;i++) cout<<x[i]<<endl;
}

