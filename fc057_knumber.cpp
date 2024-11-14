#include <bits/stdc++.h>
#define ll long long int

using namespace std;

const ll N=100005;
ll n,k,a[N];
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>n>>k;
    for (ll i=1;i<=n;i++) cin>>a[i];
    sort(a+1,a+n+1);
    cout<<a[k];
}

