#include <bits/stdc++.h>
#define ll long long int

using namespace std;

ll n;
ll kt(ll n){
    ll s=0;
    while (n>0){
        s+=n%10;
        n/=10;
    }
    if (s%4==0) return 1;
    return 0;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>n;
    ll m=n;
    while (kt(m)==0) m++;
    cout<<m;
}

