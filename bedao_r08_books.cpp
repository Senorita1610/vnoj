#include <bits/stdc++.h>
#define ll long long int

using namespace std;

const ll N=100005;
ll n,q,d,x,a[N],mp[N]={};
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>n>>q;
    for (ll i=1;i<=q;i++) cin>>a[i];
    for (ll i=q;i>=1;i--)
        if (mp[a[i]]==0){
            cout<<a[i]<<endl;
            mp[a[i]]=1;
        }
    for (ll i=1;i<=n;i++)
        if (mp[i]==0) cout<<i<<endl;
}

