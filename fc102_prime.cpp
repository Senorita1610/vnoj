#include <bits/stdc++.h>
#define ll long long int

using namespace std;

const ll N=10000005;
ll t,a,b,x[N]={};
double y[N],z[N];
void SangNt(){
    x[1]=1;
    ll i=1;
    while (i<=sqrt(N)){
        while (x[i]==1) i++;
        for (ll j=2;j<=N/i;j++)
            x[i*j]=1;
        i++;
    }
}
void Build(){
    y[1]=0,z[1]=0;
    for (ll i=2;i<=N-5;i++){
        y[i]=y[i-1];
        if (x[i]==0) y[i]+=i;
    }
    for (ll i=2;i<=N-5;i++)
        z[i]=z[i-1]+(x[i]==0);

}
void Solve(){
    cin>>a>>b;
    cout<<fixed<<setprecision(2)<<(y[b]-y[a-1])/(z[b]-z[a-1])<<endl;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    SangNt();
    Build();
    cin>>t;
    while (t--) Solve();
}

