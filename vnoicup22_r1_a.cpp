#include <bits/stdc++.h>
#define ll long long int

using namespace std;

const ll N=100000;
ll n,a[N+5],b[N+5];
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>n;
    for (ll i=1;i<=n;i++) cin>>a[i];
    for (ll i=1;i<=n;i++) cin>>b[i];
    if (a[n]!=b[1]){
        for (ll i=1;i<=n;i++) cout<<'a';
        for (ll i=1;i<=n;i++) cout<<'b';
    }
    else{
        for (ll i=1;i<n;i++) cout<<'a';
        for (ll i=1;i<=n;i++) cout<<'b';
        cout<<'a';
    }
}

