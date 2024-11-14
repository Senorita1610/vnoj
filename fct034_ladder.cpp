#include <bits/stdc++.h>
#define ll long long int

using namespace std;

const ll N=100005;
ll n,q,a[N],ans[N],x,y;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>n>>q;
    for (ll i=1;i<=n;i++) cin>>a[i];
    ll i=1;
    while (i<=n){
        ll j=i-1;
        while (i<=n && a[i]>=a[i-1]){
            ans[i]=j;
            i++;
        }
        while (i<=n && a[i]<=a[i-1]){
            ans[i]=j;
            i++;
        }
    }
    while (q--){
        cin>>x>>y;
        (ans[y]<=x) ? cout<<"Yes"<<endl : cout<<"No"<<endl;
    }
}

