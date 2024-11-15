#include <bits/stdc++.h>
#define ll long long int

using namespace std;

ll a[10];
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    for (ll i=1;i<=5;i++) cin>>a[i];
    for (ll i=5;i>=1;i--)
        while (a[i]--) cout<<i;
}

