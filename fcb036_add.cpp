#include <bits/stdc++.h>
#define ll long long int

using namespace std;

const ll N=105;
ll t,n,a[N];
void Solve(){
    cin>>n;
    for (ll i=1;i<=n;i++) cin>>a[i];
    for (ll i=1;i<n-1;i++)
        for (ll j=i+1;j<n;j++)
            for (ll k=j+1;k<=n;k++)
                if (a[i]+a[j]==a[k] || a[j]+a[k]==a[i] || a[k]+a[i]==a[j]){
                    cout<<"YES"<<endl;
                    return;
                }
    cout<<"NO"<<endl;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>t;
    while (t--) Solve();
}

