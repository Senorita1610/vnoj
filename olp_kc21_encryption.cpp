#include <bits/stdc++.h>
#define ll long long int

using namespace std;

ll l,r,a,k;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>l>>r>>a>>k;
    k/=__gcd(a,k);
    if (l%k==0) cout<<r/k-l/k+1;
    else cout<<r/k-l/k;
}

