#include <bits/stdc++.h>
#define ll long long int

using namespace std;

ll n,m=-1e+18,e;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>n;
    ll a[n+1];
    a[0]=0;
    for ( ll i=1; i <= n; i++){
        cin>>a[i];
        if (a[i-1]>0) a[i]+=a[i-1];
        m=max(m,a[i]);
    }
    cout<<m;
}

