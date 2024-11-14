#include <bits/stdc++.h>
#define ll long long int

using namespace std;

ll n,s=0;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>n;
    ll a[n+1],b[n+1];
    unordered_map <ll,ll> mp1,mp2;
    for (ll i=1;i<=n;i++){
        cin>>a[i]>>b[i];
        mp1[a[i]]++;
        mp2[b[i]]++;
    }
    for (ll i=1;i<=n;i++)
        s+=(mp1[a[i]]-1)*(mp2[b[i]]-1);
    cout<<s;
}

