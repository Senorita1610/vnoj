#include <bits/stdc++.h>
#define ll long long int

using namespace std;

const ll N=25005;
ll n,a[N];
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>n;
    a[0]=0;
    for (ll i=2;i<=n;i++) cin>>a[i];
    a[1]=a[2];
    for (ll i=2;i<=n;i++) a[i]=min(a[i-2],a[i-1])+a[i];
    cout<<a[n];
}

