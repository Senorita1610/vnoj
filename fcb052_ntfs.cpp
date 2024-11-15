#include <bits/stdc++.h>
#define ll long long int

using namespace std;

ll n;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>n;
    (n%4096==0) ? cout<<n/4096*4 : cout<<n/4096*4+4;
}

