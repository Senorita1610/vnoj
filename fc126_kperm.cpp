#include <bits/stdc++.h>
#define ll long long int

using namespace std;

ll n,k,x,y;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>n>>k;
    x=1,y=k+1;
    while (x<y){
        cout<<x<<" "<<y<<" ";
        x++;y--;
        if (x==y) cout<<x<<" ";
    }
    for (ll i=k+2;i<=n;i++) cout<<i<<" ";
}

