#include <bits/stdc++.h>
#define ll long long int

using namespace std;

ll t,n;
ll Change(ll n){
    ll s=0;
    while (n>0){
        s+=(n%10)*(n%10);
        n/=10;
    }
    return s;
}
void Solve(){
    cin>>n;
    unordered_map <ll,ll> mp;
    while (n>1){
        mp[n]=1;
        n=Change(n);
        if (mp[n]==1){
            cout<<"NO"<<endl;
            return;
        }
    }
    cout<<"YES"<<endl;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>t;
    while (t--) Solve();
}

