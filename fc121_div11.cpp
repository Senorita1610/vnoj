#include <bits/stdc++.h>
#define ll long long int

using namespace std;

ll n,x,ans=0,a[15]={};
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>n;
    for (ll i=1;i<=n;i++){
        cin>>x;
        ans+=a[11-x]+a[x];
        a[x]++;
    }
    cout<<ans;
}

