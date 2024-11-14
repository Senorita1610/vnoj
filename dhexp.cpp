#include<bits/stdc++.h>
#define ll long long
using namespace std;
int main() {
    ll n,k;
    cin>>n>>k;
    ll a[n];
    for (int i=0;i<n;i++) {
        cin>>a[i];
    }
    ll res=a[0];
    sort(a+1,a+n,greater<ll>());
    for (int i=1;i<=k;i++) res+=a[i];
    for (int i=k+1;i<n;i++) res-=a[i];
    cout<<res;
}

