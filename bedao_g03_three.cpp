#include <bits/stdc++.h>
#define ll long long int

using namespace std;

ll t,n,x;
ll Pr(ll n){
    if (n<=3) return n>1;
    if (n%2==0 || n%3==0) return 0;
    ll i=5;
    while (i*i<=n){
        if (n%i==0 || n%(i+2)==0) return 0;
        i+=6;
    }
    return 1;
}
ll Check(ll n){
    x=(ll)sqrt(n);
    if (x*x!=n) return 0;
    return Pr(x);
}
void Solve(){
    cin>>n;
    cout<<Check(n)<<endl;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>t;
    while (t--) Solve();
}

