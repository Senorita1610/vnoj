#include <bits/stdc++.h>
#define ll long long int

using namespace std;

ll a,b;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>a>>b;
    if (a>b) for (ll i=1;i<=a;i++) cout<<b;
    else for (ll i=1;i<=b;i++) cout<<a;
}

