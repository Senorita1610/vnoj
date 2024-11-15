#include <bits/stdc++.h>
#define ll long long int

using namespace std;

const ll N=60005;
ll n,t[N],r[N],f[N];
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>n;
    for (ll i=1;i<=n;i++) cin>>t[i];
    for (ll i=1;i<n;i++) cin>>r[i];
    f[1]=t[1];
    f[2]=min(t[1]+t[2],r[1]);
    for (ll i=3;i<=n;i++)
        f[i]=min(f[i-1]+t[i],f[i-2]+r[i-1]);
    cout<<f[n];
}

