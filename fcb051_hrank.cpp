#include <bits/stdc++.h>
#define ll long long int

using namespace std;

const ll N=1000;
ll n,q,a,x[N+5],mp[N+5]={};
void Chen(ll a, ll i){
    for (ll j=a+1;j>i;j--) x[j]=x[j-1];
    x[i]=a;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>n>>q;
    x[1]=1;
    for (ll i=2;i<=n;i++){
        cin>>a;
        Chen(i,a+1);
    }
    for (ll i=1;i<=n;i++) mp[x[i]]=i;
    while (q--){
        cin>>a;
        cout<<mp[a]<<endl;
    }
}

