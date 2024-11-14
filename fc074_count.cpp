#include <bits/stdc++.h>
#define ll long long int

using namespace std;

const ll MOD=1e9+7;
ll n,ans=1;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>n;
    n--;
    while (n>0){
        ll d=1,s=3;
        while (d*2<=n){
            d*=2;
            s=(s*s)%MOD;
        }
        n-=d;
        ans=(ans*s)%MOD;
    }
    cout<<ans;
}

