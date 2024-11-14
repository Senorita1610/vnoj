#include <bits/stdc++.h>
#define ll long long int

using namespace std;

ll n,k,a,b;
vector <pair<ll,ll>> v;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>n;
    for (ll i=1;i<=n;i++){
        cin>>a>>b;
        v.emplace_back(a,b);
    }
    cin>>k;
    sort(v.begin(),v.end());
    for (ll i=0;i<v.size();i++){
        k-=v[i].second;
        if (k<=0){
            cout<<v[i].first;
            return 0;
        }
    }
}

