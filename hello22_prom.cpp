#include <bits/stdc++.h>
#define ll long long int

using namespace std;

ll t,n,a,b;
void Solve(){
    cin>>n>>a>>b;
    ll d=__gcd(a,b);
    a/=d,b/=d;
    n/=(a+b);
    cout<<n*min(a,b)<<" "<<n*max(a,b)<<endl;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>t;
    while (t--) Solve();
}

