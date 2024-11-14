#include <bits/stdc++.h>
#define ll long long int

using namespace std;

const ll N=300,inf=1e+18;
ll n,m,x,y,w,o=1,ans=-inf,a[N+5][N+5]={};
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>n>>m;
    while (m--){
        cin>>x>>y>>w;
        for (ll i=max(o,x-w+1);i<=min(n,x+w-1);i++)
            for (ll j=max(o,y-w+1);j<=min(n,y+w-1);j++)
                a[i][j]+=w-max(abs(x-i),abs(y-j));
    }
    for (ll i=1;i<=n;i++)
        for (ll j=1;j<=n;j++)
            ans=max(ans,a[i][j]);
    cout<<ans;
}

