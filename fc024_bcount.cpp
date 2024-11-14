#include <bits/stdc++.h>
#define ll long long int

using namespace std;

const ll N=100005;
ll n,q,x,y,a[4][N];
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>n>>q;
    a[1][0]=0;
    a[2][0]=0;
    a[3][0]=0;
    for (ll i=1;i<=n;i++){
        cin>>x;
        for (ll j=1;j<=3;j++) a[j][i]=a[j][i-1];
        a[x][i]++;
    }
    while (q--){
        cin>>x>>y;
        for (ll i=1;i<=3;i++) cout<<a[i][y]-a[i][x-1]<<" ";
        cout<<endl;
    }
}

