#include <bits/stdc++.h>
#define ll long long int

using namespace std;

const ll N=50,MOD=1000001;
ll t,n,m,k,x[N+5]={};
void Build(){
    for (ll i=2;i<=N;i++)
        if (!x[i])
            for (ll j=1;j<=N/i;j++)
                x[i*j]=i;
}
void Solve(){
    cin>>n>>m>>k;
    if (k>min(n,m)){
        cout<<0<<endl;
        return;
    }
    ll ans=1,o,a[N+5]={};
    for (ll i=1;i<=k;i++){
        o=n-i+1;
        while (o>1){a[x[o]]++;o/=x[o];}
        o=m-i+1;
        while (o>1){a[x[o]]++;o/=x[o];}
        o=i;
        while (o>1){a[x[o]]--;o/=x[o];}
    }
    for (ll i=1;i<=N;i++)
        for (ll j=1;j<=a[i];j++)
            ans=(ans*i)%MOD;
    cout<<ans<<endl;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    Build();
    cin>>t;
    while (t--) Solve();
}

