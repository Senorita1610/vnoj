#include <bits/stdc++.h>
#define ll long long int

using namespace std;

const ll N=100005,inf=1e+18;
ll n,q,x,y,a[N]={};
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>n>>q;
    while (q--){
        cin>>x>>y;
        a[x]++;
        a[y+1]--;
    }
    a[0]=0;
    for (ll i=1;i<=n;i++){
        a[i]=(a[i]+a[i-1]+inf)%2;
        cout<<a[i]<<" ";
    }
}

