#include <bits/stdc++.h>
#define ll long long int

using namespace std;

const ll inf=1e+18;
ll t,n,x2=1,x3=1,x5=1;
vector <ll> v;
unordered_map <ll,ll> mp;
ll Sosanh(ll x, ll y, ll z){
    if (x>inf/y) return 0;
    x*=y;
    if (x>inf/z) return 0;
    return 1;
}
void Build(){
    for (ll i=1;i<=64;i++){
        x3=1;
        for (ll j=1;j<=64;j++){
            x5=1;
            for (ll k=1;k<=64;k++){
                if (Sosanh(x2,x3,x5)==1) v.push_back(x2*x3*x5);
                if (x5>inf/5) break;
                else x5*=5;
            }
            if (x3>inf/3) break;
            else x3*=3;
        }
        if (x2>inf/2) break;
        else x2*=2;
    }
    sort(v.begin(),v.end());
    for (ll i=0;i<v.size();i++) mp[v[i]]=i+1;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>t;
    Build();
    while (t--){
        cin>>n;
        (mp[n]==0) ? cout<<"Not in sequence"<<endl : cout<<mp[n]<<endl;
    }
}

