#include <bits/stdc++.h>
#define ll long long int

using namespace std;

const ll N=200005;
ll n,k,x,a[N];
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>n>>k;
    for (ll i=1;i<=n;i++){
        cin>>a[i];
        a[i]+=k;
    }
    while (k--){
        cin>>x;
        a[x]--;
    }
    for (ll i=1;i<=n;i++) cout<<a[i]<<" ";
}

