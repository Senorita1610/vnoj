#include <bits/stdc++.h>
#define ll long long int

using namespace std;

const ll N=10005;
ll n,a[N];
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>n;
    for (ll i=1;i<=n;i++) cin>>a[i];
    sort(a+1,a+n+1);
    cout<<max(a[1]*a[2],max(a[n-1]*a[n],max(a[1]*a[2]*a[3],max(a[n-2]*a[n-1]*a[n],max(a[1]*a[2]*a[n],a[1]*a[n-1]*a[n])))));
}

