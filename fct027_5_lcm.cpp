#include <bits/stdc++.h>
#define ll long long int

using namespace std;

const ll A=1000000,MOD=1e9+7;
ll t,a,b,x[A+5]={};
void Build(){
    for (ll i=2;i<=A;i++)
        if (x[i]==0)
            for (ll j=1;j<=A/i;j++)
                x[i*j]=i;
}
void Solve(){
    cin>>a>>b;
    ll ans=1,y[A+5]={};
    for (ll i=a;i<=b;i++){
        ll o=i;
        while (o>1){
            y[x[o]]++;
            o/=x[o];
        }
    }
    for (ll i=1;i<=A;i++)
        ans=(ans*(2*y[i]+1))%MOD;
    cout<<ans<<endl;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    Build();
    cin>>t;
    while (t--) Solve();
}

