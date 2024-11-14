#include <bits/stdc++.h>
#define ll long long int

using namespace std;

const ll N=5005;
ll n,a[2*N+1];
unordered_map <ll,ll> mp;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>n;
    for (ll i=1;i<=2*n+1;i++) cin>>a[i];
    sort(a+1,a+2*n+2);
    for (ll i=2;i<=2*n;i+=2)
        if (a[i]!=a[i-1]){
            cout<<a[i-1];
            return 0;
        }
    cout<<a[2*n+1];
}

