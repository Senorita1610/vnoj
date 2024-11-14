#include <bits/stdc++.h>
#define ll long long int

using namespace std;

const ll N=1000005,inf=1e+18;
ll n,x[N],y=-inf,a,b,c,f,a1,b1,ans=0;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>n;
    for (ll i=1;i<=n;i++){
        cin>>x[i];
        y=max(y,x[i]);
    }
    cin>>a>>b>>c>>f;
    for (ll i=1;i<=n;i++)
        if (x[i]==y){
            a1=i;
            break;
        }
    for (ll i=n;i>=1;i--)
        if (x[i]==y){
            b1=i;
            break;
        }
    for (ll i=2;i<a1;i++)
        if (x[i]<x[i-1]){
            ans+=f*(x[i-1]-x[i]);
            x[i]=x[i-1];
        }
    for (ll i=n-1;i>b1;i--)
        if (x[i]<x[i+1]){
            ans+=f*(x[i+1]-x[i]);
            x[i]=x[i+1];
        }
    for (ll i=a1;i<=b1;i++) ans+=f*(y-x[i]);
    cout<<y*(a+c)+n*b<<" "<<ans;
}

