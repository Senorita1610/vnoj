#include <bits/stdc++.h>
#define ll long long int

using namespace std;

const ll inf=1e+18;
ll n,a,x=inf,y=-inf;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>n;
    while (n--){
        cin>>a;
        x=min(x,a);
        y=max(y,a);
    }
    if (x>=0 && y>=0) cout<<2*max(x,y);
    else if (x<=0 && y<=0) cout<<-2*min(x,y);
    else cout<<2*y-2*x;
}

