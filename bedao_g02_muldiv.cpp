#include <bits/stdc++.h>
#define ll long long int

using namespace std;

const ll MOD=998244353;
ll t,n;
void Solve(){
    cin>>n;
    ll ans=1,s=1,d=0,x=sqrt(n),n1=n;
    for (ll i=2;i<=sqrt(n);i++)
        if (n%i==0){
            while (n%i==0){
                d++;
                n/=i;
            }
            s*=(d+1);
            d=0;
        }
    if (n!=1) s*=2;
    for (ll i=1;i<=s/2;i++)
        ans=(ans*n1)%MOD;
    if (s%2==1) ans=(ans*x)%MOD;
    cout<<ans<<endl;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>t;
    while (t--) Solve();
}

