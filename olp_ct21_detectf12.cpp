#include <bits/stdc++.h>
#define ll long long int

using namespace std;

const ll N=1005;
ll n,F0,F1=0,F2=0,d,x[N],y[N],mp[N]={};
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>n>>F0>>d;
    mp[F0]=-1;
    for (ll i=1;i<=n;i++) cin>>x[i]>>y[i];
    for (ll i=1;i<=n;i++)
        if (mp[i]==0 && (x[i]-x[F0])*(x[i]-x[F0])+(y[i]-y[F0])*(y[i]-y[F0])<d*d){
            mp[i]=1;
            F1++;
        }
    for (ll i=1;i<=n;i++)
        if (mp[i]==1)
            for (ll j=1;j<=n;j++)
                if (mp[j]==0 && (x[i]-x[j])*(x[i]-x[j])+(y[i]-y[j])*(y[i]-y[j])<d*d){
                    mp[j]=2;
                    F2++;
                }
    cout<<F1<<" "<<F2;
}

