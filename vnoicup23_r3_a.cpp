#include <bits/stdc++.h>
#define ll long long int

using namespace std;

const ll N=100;
ll t,n,a,b,x[N+5];
ll Check(ll a, ll b){
    for (ll i=1;i<=n;i++)
        if (x[i]>x[1]+a && x[i]<x[n]-b) return 0;
    return 1;
}
void Solve(){
    cin>>n>>a>>b;
    for (ll i=1;i<=n;i++) cin>>x[i];
    (!Check(b,a) && !Check(a,b)) ? cout<<"NO"<<endl : cout<<"YES"<<endl;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>t;
    while (t--) Solve();
}

