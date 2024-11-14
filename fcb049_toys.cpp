#include <bits/stdc++.h>
#define ll long long int

using namespace std;

ll n,k,o=0;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>n>>k;
    if (k<=n+1) cout<<(k-1)/2;
    else (k%2==1) ? cout<<max(o,n-(k-1)/2) : cout<<max(o,n-k/2);
}

