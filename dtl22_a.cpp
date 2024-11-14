#include <bits/stdc++.h>
#define ll long long int

using namespace std;

const ll N=105;
ll t,n,a[N];
void Solve(){
    cin>>n;
    a[0]=0;
    for (ll i=1;i<=n;i++) cin>>a[i];
    sort(a+1,a+n+1);
    for (ll i=1;i<=n;i++) a[i]+=a[i-1];
    for (ll i=n;i>=3;i--)
        if (a[i]<a[i-1]*2){
            cout<<a[i]<<endl;
            return;
        }
    cout<<0<<endl;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>t;
    while (t--) Solve();
}

