#include <bits/stdc++.h>
#define ll long long int

using namespace std;

const ll A=1000000;
ll t,a,b,d,x[A+5]={};
ll Get(ll n){
    ll s=0;
    while (n>1){
        s++;
        n/=x[n];
    }
    return s;
}
void Build(){
    for (ll i=2;i<=A;i++)
        if (!x[i])
            for (ll j=1;j<=A/i;j++)
                x[i*j]=i;
}
void Solve(){
    cin>>a>>b;
    d=__gcd(a,b);
    cout<<max(Get(a/d),Get(b/d))<<endl;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    Build();
    cin>>t;
    while (t--) Solve();
}

