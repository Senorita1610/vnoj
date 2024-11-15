#include <bits/stdc++.h>
#define ll long long int

using namespace std;

ll n,x;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>n;
    for (ll i=1;i<=n;i++)
        for (ll j=1;j<=n;j++){
            cin>>x;
            if (i==j) cout<<sqrt(x)<<" ";
        }
}

