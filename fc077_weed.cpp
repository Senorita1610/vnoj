#include <bits/stdc++.h>
#define ll long long int

using namespace std;

const ll inf=1e+18;
ll n,a,x=inf,y=-inf;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>n;
    while (n--){
        cin>>a;
        x=min(x,a);
        y=max(y,a);
    }
    cout<<y-x;
}

