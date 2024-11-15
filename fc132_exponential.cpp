#include <bits/stdc++.h>
#define ll long long int

using namespace std;

ll n,ans=-1e+18;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>n;
    if (n==1){
        cout<<1;
        return 0;
    }
    for (ll i=2;i<=sqrt(n);i++)
        for (ll j=2;j<=50;j++)
            if (pow(i,j)<=n){
                ll x=pow(i,j);
                ans=max(ans,x);
            }
            else break;
    cout<<ans;
}

