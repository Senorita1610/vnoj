#include <bits/stdc++.h>
#define ll long long int

using namespace std;

const ll N=500005;
ll n,a[N],x=0,ans=0;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>n;
    a[0]=0;
    for (ll i=1;i<=n;i++){
        cin>>a[i];
        a[i]+=a[i-1];
    }
    for (ll i=1;i<=n;i++){
        if (a[i]*3==a[n]*2 && i>1 && i<n) ans+=x;
        if (a[i]*3==a[n] && i<n-1) x++;
    }
    cout<<ans;
}

