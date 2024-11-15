#include <bits/stdc++.h>
#define ll long long int

using namespace std;

const ll inf=1e+18;
ll n,a,x=-inf,ans=-inf;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>n;
    for (ll i=1;i<=n;i++){
        cin>>a;
        if (i>1) ans=max(ans,x-a);
        x=max(x,a);
    }
    (ans>0) ? cout<<ans : cout<<"Lo nang roi!";
}

