#include <bits/stdc++.h>
#define ll long long int

using namespace std;

const ll N=1000005;
ll n,q,c,k,a[N];
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>n>>q;
    for (ll i=1;i<=n;i++) cin>>a[i];
    sort(a+1,a+n+1,greater<ll>());
    a[0]=0;
    for (ll i=1;i<=n;i++) a[i]+=a[i-1];
    while (q--){
        cin>>c>>k;
        cout<<a[c]+a[c/(k+1)]<<endl;
    }
}

