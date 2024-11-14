#include <bits/stdc++.h>
#define ll long long int

using namespace std;

const ll N=105;
ll t,n,k,a;
void Solve(){
    ll m=0,x=0;
    cin>>n>>k;
    for (ll i=1;i<=n;i++){
        cin>>a;
        m=max(m,a);
        x+=a;
    }
    (k-m*n+x>=0 && (k-m*n+x)%n==0) ? cout<<"YES"<<endl : cout<<"NO"<<endl;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>t;
    while (t--) Solve();
}

