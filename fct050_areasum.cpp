#include <bits/stdc++.h>
#define ll long long int

using namespace std;

const ll N=100000,MOD=1e9+7;
ll n,m,ans1=0,ans2=0,a[N+5];
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>n>>m;
    a[0]=0;
    for (ll i=1;i<=n;i++){
        cin>>a[i];
        if (i>1) ans1=(ans1+a[i]*(i-1)-a[i-1])%MOD;
        a[i]+=a[i-1];
    }
    a[0]=0;
    for (ll i=1;i<=m;i++){
        cin>>a[i];
        if (i>1) ans2=(ans2+a[i]*(i-1)-a[i-1])%MOD;
        a[i]+=a[i-1];
    }
    cout<<(ans1*ans2)%MOD;
}

