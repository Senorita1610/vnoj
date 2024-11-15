#include <bits/stdc++.h>
#define ll long long int

using namespace std;

ll n,s=0,a;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>n;
    for (ll i=1;i<=n;i++){
        cin>>a;
        if (i%2==0) s+=a;
    }
    cout<<s;
}

