#include <bits/stdc++.h>
#define ll long long int

using namespace std;

ll n,s;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>n>>s;
    cout<<n*(n+1)/2-s;
}

