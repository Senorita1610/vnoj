#include <bits/stdc++.h>
#define ll long long int

using namespace std;

const ll N=10000005;
ll n,k,a[N]={},ans,d,e;
void SangNt(){
    a[0]=1;a[1]=1;
    ll i=1;
    while (i*i<=N){
        while (a[i]==1) i++;
        for (ll j=2;j<=N/i;j++)
            a[i*j]=1;
        i++;
    }
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    SangNt();
    cin>>n>>k;
    ans=0;d=1;e=0;
    for (ll i=1;i<=n;i++){
        e+=a[i]==0;
        while (e>=k){
            e-=a[d]==0;
            d++;
        }
        if (e<k && a[d-1]==0){
            e++;
            d--;
        }
        ans+=d*(e==k);
    }
    cout<<ans;
}

