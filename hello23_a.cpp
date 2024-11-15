#include <bits/stdc++.h>
#define ll long long int

using namespace std;

ll t,n,k;
void Solve(){
    cin>>n>>k;
    ll a[n+1];
    for (ll i=1;i<=n;i++) cin>>a[i];
    sort(a+1,a+n+1,greater<ll>());
    a[n+1]=0;
    for (ll i=k;i>=1;i--)
        if (a[i]!=a[i+1]){
            cout<<a[i+1]+1<<endl;
            return;
        }
    cout<<-1<<endl;
    return;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>t;
    while (t--) Solve();
}

