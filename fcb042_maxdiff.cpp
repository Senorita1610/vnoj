#include <bits/stdc++.h>
#define ll long long int

using namespace std;

const ll inf=1e+18;
ll n,a,x=-inf,y=inf;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>n;
    for (ll i=1;i<=n;i++){
        cin>>a;
        y=min(y,a);
        x=max(x,a);
    }
    cout<<x-y;
}

