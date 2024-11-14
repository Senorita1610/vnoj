#include <bits/stdc++.h>
#define ll long long int

using namespace std;

ll n,x=1,ans=0;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>n;
    for (ll i=1;i<=64;i++){
        if (i!=1) x*=2;
        if (x<=n) ans=max(ans,x);
        if (3*x<=n) ans=max(ans,3*x);
    }
    cout<<n-ans;
}

