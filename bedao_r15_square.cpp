#include <bits/stdc++.h>
#define ll long long int

using namespace std;

const ll N=1005,inf=1e+8;
ll n;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>n;
    for (ll i=1;i<n;i++) cout<<i<<" ";
    cout<<inf-n*(n-1)/2;
}

