#include <bits/stdc++.h>
#define ll long long int

using namespace std;

const ll N=100005;
ll n,a[N],x=0,ans=-1;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>n;
    for (ll i=1;i<=n;i++) cin>>a[i];
    for (ll i=n;i>=1;i--)
        if (a[i]>x){
            ans++;
            x=a[i];
        }
    cout<<ans;
}

