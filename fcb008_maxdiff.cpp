#include <bits/stdc++.h>
#define ll long long int

using namespace std;

ll n,s=0;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>n;
    ll a[n+1];
    for (ll i=1;i<=n;i++)
        cin>>a[i];
    for (ll i=3;i<=n;i++)
        s=max(s,a[i]-a[i-2]);
    cout<<s;
}

