#include <bits/stdc++.h>
#define ll long long int

using namespace std;

ll n,s,a,t=0;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>n>>s;
    for (ll i=1;i<=n;i++){
        cin>>a;
        t+=a;
    }
    (t>=s) ? cout<<"YES" : cout<<"NO";
}

