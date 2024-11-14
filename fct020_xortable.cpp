#include <bits/stdc++.h>
#define ll long long int

using namespace std;

const ll N=105;
ll n,x,a[N];
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>n;
    for (ll i=1;i<=n;i++) cin>>a[i];
    for (ll i=1;i<=n;i++){
        for (ll j=1;j<=n;j++){
            x=a[i]^a[j];
            cout<<x<<" ";
        }
        cout<<endl;
    }
}

