#include <bits/stdc++.h>
#define ll long long int

using namespace std;

const ll N=200005,inf=1e+18;
ll n,a[N],mp[N]={},ans=inf,d=-1;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>n;
    for (ll i=1;i<=n;i++){
        cin>>a[i];
        mp[a[i]]++;
    }
    for (ll i=1;i<=n;i++)
        if (mp[a[i]]==1)
            if (a[i]<ans){
                ans=a[i];
                d=i;
            }
    cout<<d;
}

