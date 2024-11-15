#include <bits/stdc++.h>
#define ll long long int

using namespace std;

const ll z=1e9+7,N=100005;
ll n,s=0,d=0,e=0,a[N];
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>n;
    for (ll i=1;i<=n;i++){
        cin>>a[i];
        e=(e+d*a[i])%z;
        d=(d+a[i]*s)%z;
        s+=a[i];
    }
    cout<<e;
}

