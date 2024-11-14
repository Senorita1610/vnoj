#include <bits/stdc++.h>
#define ll long long int

using namespace std;

const ll N=30005,inf=1e+18;
ll n,p,x,d,ans=inf,a[N]={},b[N]={};
void SangUoc(){
    for (ll i=2;i<=N;i++)
        if (a[i]==0)
            for (ll j=1;j<=N/i;j++)
                a[i*j]=i;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    SangUoc();
    cin>>n>>p;
    for (ll i=2;i<=n;i++){
        x=i;
        while (x>1){
            b[a[x]]++;
            x/=a[x];
        }
    }
    for (ll i=2;i<=p;i++)
        if (p%i==0){
            d=0;
            while (p%i==0){
                p/=i;
                d++;
            }
            ans=min(ans,b[i]/d);
        }
    cout<<ans;
}

