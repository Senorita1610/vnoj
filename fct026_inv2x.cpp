#include <bits/stdc++.h>
#define ll long long int

using namespace std;

ll n,s=0;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>n;
    ll a[n+1];
    for (ll i=1;i<=n;i++) cin>>a[i];
    for (ll i=1;i<n;i++)
        for (ll j=i+1;j<=n;j++)
            if (a[i]>2*a[j]) s++;
    cout<<s;
}

