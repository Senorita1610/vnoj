#include <bits/stdc++.h>
#define ll long long int

using namespace std;

const ll inf=1e+18;
ll n,q,a,x=inf,y=-inf,z;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>n>>q;
    for (ll i=1;i<=n;i++){
        cin>>a;
        x=min(x,a);
        y=max(y,a);
    }
    while (q--){
        cin>>z;
        (z>=x && z<=y) ? cout<<"Yes"<<endl : cout<<"No"<<endl;
    }
}

