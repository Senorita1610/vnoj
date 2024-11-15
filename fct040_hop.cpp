#include <bits/stdc++.h>
#define ll long long int
using namespace std;
ll n,k;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>n>>k;
    (n%k==0) ? cout<<n/k : cout<<n/k+1;
}

