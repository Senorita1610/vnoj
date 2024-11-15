#include <bits/stdc++.h>
#define ll long long int

using namespace std;

ll a,b,x,m=1e+18;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>a>>b;
    for (ll i=1;i<=a;i++){
        cin>>x;
        b-=x;
        m=min(m,x);
    }
    cout<<a+b/m;
}

