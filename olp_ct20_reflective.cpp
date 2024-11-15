#include <bits/stdc++.h>
#define ll long long int

using namespace std;

const ll inf=1e+18;
ll a,b;
ll Cal(ll x){
    ll ans=0;
    for (ll i=2;i<=inf;i*=2)
        ans+=x/i;
    return ans;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>a>>b;
    cout<<Cal(b)-Cal(a-1);
}

