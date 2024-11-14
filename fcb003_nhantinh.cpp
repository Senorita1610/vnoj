#include <bits/stdc++.h>
#define ll long long int

using namespace std;

const ll N=100005;
ll n,a[N];
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>n;
    for (ll i=1;i<=n;i++) cin>>a[i];
    for (ll i=1;i<=n;i++)
        for (ll j=1;j<=n/i;j++)
            if (a[i]*a[j]!=a[i*j]){
                cout<<"NO";
                return 0;
            }
    cout<<"YES";
}

